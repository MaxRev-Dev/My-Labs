
import re


class RomanError(Exception): pass
class OutOfRangeError(RomanError): pass
class NotIntegerError(RomanError): pass
class InvalidRomanNumeralError(RomanError): pass


class RomanConverter:
    def __init__(self):
        self.fillLookupTables()
        pass
     
    MAX_ROMAN_NUMERAL = 4999 # when m is 1000 max
     
    romanNumeralMap = (('M',  1000),
                       ('CM', 900),
                       ('D',  500),
                       ('CD', 400),
                       ('C',  100),
                       ('XC', 90),
                       ('L',  50),
                       ('XL', 40),
                       ('X',  10),
                       ('IX', 9),
                       ('V',  5),
                       ('IV', 4),
                       ('I',  1))
     
    toRomanTable = [None]  
    fromRomanTable = {}

    def toRoman(self,n):
        """convert integer to Roman numeral"""
        if not (0 < n <= self.MAX_ROMAN_NUMERAL):
            raise OutOfRangeError("number out of range (must be 1..4999)")
        if int(n) != n:
            raise NotIntegerError("non-integers can not be converted")
        return self.toRomanTable[n]

    def fromRoman(self,s):
        """convert Roman numeral to integer"""
        if not s:
            raise InvalidRomanNumeralError('Input can not be blank')
        if not (s in self.fromRomanTable):
            raise InvalidRomanNumeralError('Invalid Roman numeral: %s' % s)
        return self.fromRomanTable[s]

    def toRomanDynamic(self,n):
        """convert integer to Roman numeral using dynamic programming"""
        assert(0 < n <= self.MAX_ROMAN_NUMERAL)
        assert(int(n) == n)
        result = ""
        for numeral, integer in self.romanNumeralMap:
            if n >= integer:
                result = numeral
                n -= integer
                break  
        if n > 0:
            result += self.toRomanTable[n]
        return result

    def fillLookupTables(self):
        """compute all the possible roman numerals""" 
        for integer in range(1, self.MAX_ROMAN_NUMERAL + 1):
            romanNumber = self.toRomanDynamic(integer)
            self.toRomanTable.append(romanNumber)
            self.fromRomanTable[romanNumber] = integer 


rc = RomanConverter()

print(rc.toRoman(int(input("Enter integer number: "))))
 
print(rc.fromRoman(input("Enter roman number: ")))
