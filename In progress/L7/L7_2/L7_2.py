import io 
import time
import errno
from os import getcwd, listdir, mkdir 
from os.path import isfile, join, isdir

path = join(getcwd(), 'files')
if ( isdir(path) == False):
    print('Can\'t fing \'files\' directory')
    print('Creating new one in ' + getcwd())
    mkdir(getcwd(), 'files')

def readfile(path):
    try:
        f = open(path,'r')
        print('File contents:\n' +"".join(f.readlines())) 
        f.close();                    
    except IOError as x:
        if (x.errno == errno.ENOENT):
            print(filename + '- does not exist')
        elif x.errno == errno.EACCES:
                print(filename + '- cannot be read')
        else:
                print(filename + '- some other error')  
    except: 
        print("Contents of file cannot be read")

files = lambda: [f for f in listdir(path) if isfile(join(path, f))]
if (files() == []):
    print('Waiting for files...')  
    while (files() == []):
        time.sleep(1000)


print('WorkDir is '+ path)
print()
print('Files:\n' +"\n".join(files()))

print()
flist = files()
for filename in flist:   
           print('File ['+ str(flist.index(filename)+1) + "]: - "+ filename)
           readfile(join(path,filename))
           print()
chosen = input("Please, select index of file for append: ")
try:
    ind = int(chosen)-1;
except: 
    print("wrong input. app closing")
if (ind < len(flist)):
    f = open(join(path,flist[ind]),'a')
    text = input("Enter content to append: ");
    f.write(text)
    f.close()
    readfile(join(path,flist[ind]))