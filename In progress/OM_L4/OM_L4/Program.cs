using System;
using System.Linq;

namespace Grad
{
    internal class Program
    {

        private static Func<double[], double>[] Dx;

        private static double[] FindGrad(double[] x)
        {
            var dfDx = Dx.Select(f => f(x)).ToArray();

            double norm = Math.Sqrt(dfDx.Select(v => Math.Pow(v, 2)).Sum());

            return dfDx.Select(v => v / norm).ToArray();
        }

        private static void Main(string[] args)
        {
            Dx = new Func<double[], double>[] { Dx1, Dx2, Dx3 };
            int N = Dx.Length;

            double a = 0.5, b = 0.5;
            var e = 0.00001;
            double[] x_cur = new double[N].Select(x => 1.0).ToArray(), x_next = x_cur;
            double[] grad = new double[N];

            while (true)
            {
                x_cur = x_next;
                grad = FindGrad(x_cur);
                //  x_next = x_cur.Select((x, i) => x - a * grad[i]).ToArray();

                var P = MultiplyMatrix(MatrixInverse(GetGesse(x_cur)), grad);

                x_next = x_cur.Select((cur, i) => cur - P[i]).ToArray();

                var left = F(x_cur.Select((x, i) => x + a * P[i]).ToArray()) - F(x_cur);

                var all = P.Select(gri => (left <= e * a * gri)).All(x => x);

                if (all)
                    break;
                else a *= b;

                Console.WriteLine(string.Join(" ", x_cur.Select((x, i) => $"x{i + 1}={x.ToString("f2")}")));
                Console.WriteLine($"y={F(x_cur)}");
            }
            Console.WriteLine(string.Join("\n", x_cur.Select((x, i) => $"x{i + 1}={x.ToString("f2")}")));

            Console.WriteLine($"y={F(x_cur).ToString("f2")}");

            Console.ReadKey();
        }
        public static double[] MultiplyMatrix(double[,] a, double[] b)
        {
            if (a.GetLength(1) == b.GetLength(0))
            {
                var c = new double[b.GetLength(0)];
                for (int i = 0; i < c.GetLength(0); i++)
                {
                    for (int j = 0; j < c.GetLength(0); j++)
                    {
                        c[i] = c[i] + a[i, j] * b[j];
                    }
                }
                return c;
            }
            else
            {
                Console.WriteLine("\n Number of columns in First Matrix should be equal to Number of rows in Second Matrix.");
                Console.WriteLine("\n Please re-enter correct dimensions.");
                Environment.Exit(-1);
            }
            return null;
        }


        private static double Etail(double[] x)
        {
            return Math.Pow(Math.E, Math.Pow(x[0], 2) + 2 * Math.Pow(x[1], 2) + Math.Pow(x[2], 2));
        }

        private static double F(double[] x)
        {
            return x[0] + x[1] - 5 * x[2] + Etail(x);
        }

        private static double Dx1(double[] x)
        {
            return 2 * x[0] * Etail(x) + 1;
        }
        private static double Dx2(double[] x)
        {
            return 4 * x[1] * Etail(x) + 1;
        }
        private static double Dx3(double[] x)
        {
            return 2 * x[2] * Etail(x) - 5;
        }
        private static double Dx11(double[] x)
        {
            return 2 * (2 * Math.Pow(x[0], 2) + 1) * Etail(x);
        }
        private static double Dx12(double[] x)
        {
            return 8 * x[0] * x[1] * Etail(x);
        }
        private static double Dx13(double[] x)
        {
            return 4 * x[0] * x[2] * Etail(x);
        }
        private static double Dx22(double[] x)
        {
            return 4 * (4 * Math.Pow(x[1], 2) + 1) * Etail(x);
        }
        private static double Dx23(double[] x)
        {
            return 8 * x[1] * x[2] * Etail(x);
        }
        private static double Dx33(double[] x)
        {
            return 2 * (2 * Math.Pow(x[1], 2) + 1) * Etail(x);
        }

        private static double[,] GetGesse(double[] x)
        {
            return new double[,]
            {
                { Dx11(x),Dx12(x),Dx13(x)},
                { Dx12(x),Dx22(x),Dx23(x)},
                { Dx13(x),Dx23(x),Dx33(x)}
            };
        }

        private static bool IsPositiveDefined(double[,] m)
        {
            var m1 = m[0, 0] > 0;
            var m2 = MatrixDeterminant(TrimArray(2, 2, m)) > 0;
            var m3 = MatrixDeterminant(m) > 0;
            return m1 && m2 && m3;
        }

        private static bool IsNegativeDefined(double[,] m)
        {
            var m1 = m[0, 0] > 0;
            var m2 = MatrixDeterminant(TrimArray(2, 2, m)) > 0;
            var m3 = MatrixDeterminant(m) > 0;
            return !m1 && m2 && !m3;
        }

        private static bool IsSetPoint(double[,] m)
        {
            if (!IsNegativeDefined(m) &&
                !IsPositiveDefined(m) &&
                MatrixDeterminant(m) > 0)
                return true;
            return false;
        }

        private static double[,] MatrixInverse(double[,] matrix)
        {
            int n = matrix.GetLength(0);
            double[,] result = MatrixDuplicate(matrix);

            double[,] lum = MatrixDecompose(matrix, out int[] perm,
              out int toggle);
            if (lum == null)
                throw new Exception("Unable to compute inverse");

            double[] b = new double[n];
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (i == perm[j])
                        b[j] = 1.0;
                    else
                        b[j] = 0.0;
                }

                double[] x = HelperSolve(lum, b);

                for (int j = 0; j < n; ++j)
                    result[j, i] = x[j];
            }
            return result;
        }

        private static double[] HelperSolve(double[,] luMatrix, double[] b)
        {
            // before calling this helper, permute b using the perm array
            // from MatrixDecompose that generated luMatrix
            int n = luMatrix.GetLength(0);
            double[] x = new double[n];
            b.CopyTo(x, 0);

            for (int i = 1; i < n; ++i)
            {
                double sum = x[i];
                for (int j = 0; j < i; ++j)
                    sum -= luMatrix[i, j] * x[j];
                x[i] = sum;
            }

            x[n - 1] /= luMatrix[n - 1, n - 1];
            for (int i = n - 2; i >= 0; --i)
            {
                double sum = x[i];
                for (int j = i + 1; j < n; ++j)
                    sum -= luMatrix[i, j] * x[j];
                x[i] = sum / luMatrix[i, i];
            }

            return x;
        }

        private static double[,] MatrixDecompose(double[,] matrix, out int[] perm, out int toggle)
        {
            // Doolittle LUP decomposition with partial pivoting.
            // rerturns: result is L (with 1s on diagonal) and U; perm holds row permutations; toggle is +1 or -1 (even or odd)
            int rows = matrix.GetLength(0);
            int cols = matrix.GetLength(1);

            //Check if matrix is square
            if (rows != cols)
                throw new Exception("Attempt to MatrixDecompose a non-square mattrix");

            double[,] result = MatrixDuplicate(matrix); // make a copy of the input matrix

            perm = new int[rows]; // set up row permutation result
            for (int i = 0; i < rows; ++i) { perm[i] = i; } // i are rows counter

            toggle = 1; // toggle tracks row swaps. +1 -> even, -1 -> odd. used by MatrixDeterminant

            for (int j = 0; j < rows - 1; ++j) // each column, j is counter for coulmns
            {
                double colMax = Math.Abs(result[j, j]); // find largest value in col j
                int pRow = j;
                for (int i = j + 1; i < rows; ++i)
                {
                    if (result[i, j] > colMax)
                    {
                        colMax = result[i, j];
                        pRow = i;
                    }
                }

                if (pRow != j) // if largest value not on pivot, swap rows
                {
                    double[] rowPtr = new double[result.GetLength(1)];

                    //in order to preserve value of j new variable k for counter is declared
                    //rowPtr[] is a 1D array that contains all the elements on a single row of the matrix
                    //there has to be a loop over the columns to transfer the values
                    //from the 2D array to the 1D rowPtr array.
                    //----tranfer 2D array to 1D array BEGIN

                    for (int k = 0; k < result.GetLength(1); k++)
                    {
                        rowPtr[k] = result[pRow, k];
                    }

                    for (int k = 0; k < result.GetLength(1); k++)
                    {
                        result[pRow, k] = result[j, k];
                    }

                    for (int k = 0; k < result.GetLength(1); k++)
                    {
                        result[j, k] = rowPtr[k];
                    }

                    //----tranfer 2D array to 1D array END

                    int tmp = perm[pRow]; // and swap perm info
                    perm[pRow] = perm[j];
                    perm[j] = tmp;

                    toggle = -toggle; // adjust the row-swap toggle
                }

                if (Math.Abs(result[j, j]) < 1.0E-20) // if diagonal after swap is zero . . .
                    return null; // consider a throw

                for (int i = j + 1; i < rows; ++i)
                {
                    result[i, j] /= result[j, j];
                    for (int k = j + 1; k < rows; ++k)
                    {
                        result[i, k] -= result[i, j] * result[j, k];
                    }
                }
            } // main j column loop

            return result;
        }

        private static double MatrixDeterminant(double[,] matrix)
        {
            double[,] lum = MatrixDecompose(matrix, out int[] perm, out int toggle);
            if (lum == null)
                throw new Exception("Unable to compute MatrixDeterminant");
            double result = toggle;
            for (int i = 0; i < lum.GetLength(0); ++i)
                result *= lum[i, i];

            return result;
        }
        private static double[,] MatrixDuplicate(double[,] matrix)
        {
            // allocates/creates a duplicate of a matrix. assumes matrix is not null.
            double[,] result = MatrixCreate(matrix.GetLength(0), matrix.GetLength(1));
            for (int i = 0; i < matrix.GetLength(0); ++i) // copy the values
                for (int j = 0; j < matrix.GetLength(1); ++j)
                    result[i, j] = matrix[i, j];
            return result;
        }
        private static double[,] MatrixCreate(int rows, int cols)
        {
            // allocates/creates a matrix initialized to all 0.0. assume rows and cols > 0
            // do error checking here
            double[,] result = new double[rows, cols];
            return result;
        }

        private static double[,] ExtractLower(double[,] matrix)
        {
            // lower part of a Doolittle decomposition (1.0s on diagonal, 0.0s in upper)
            int rows = matrix.GetLength(0); int cols = matrix.GetLength(1);
            double[,] result = MatrixCreate(rows, cols);
            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    if (i == j)
                        result[i, j] = 1.0f;
                    else if (i > j)
                        result[i, j] = matrix[i, j];
                }
            }
            return result;
        }

        private static double[,] ExtractUpper(double[,] matrix)
        {
            // upper part of a Doolittle decomposition (0.0s in the strictly lower part)
            int rows = matrix.GetLength(0); int cols = matrix.GetLength(1);
            double[,] result = MatrixCreate(rows, cols);
            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    if (i <= j)
                        result[i, j] = matrix[i, j];
                }
            }
            return result;
        }
        public static T[,] TrimArray<T>(int row, int column, T[,] original)
        {
            T[,] resultant = new T[original.GetLength(0) - 1, original.GetLength(1) - 1];

            for (int i = 0, j = 0; i < original.GetLength(0); i++)
            {
                if (i == row)
                    continue;

                for (int k = 0, u = 0; k < original.GetLength(1); k++)
                {
                    if (k == column)
                        continue;

                    resultant[j, u] = original[i, k];
                    u++;
                }
                j++;
            }
            return resultant;
        }
    }
}

