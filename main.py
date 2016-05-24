from phoneword import Phoneword
import sys
import getopt

def main():
    try:
        opts, args = getopt.getopt( sys.argv[1 : ], "h", ["help"] )
    except getopt.error, msg:
        print( msg )
        return 2
    
    for arg in args:
        try:
            input = int(arg)
        except ValueError:
            print( "Must enter an integer value!" )
            return 1
        print( Phoneword(input) )
        print("\n")
    #END FOR
    return 0
    
# END MAIN

if __name__ == "__main__":
    sys.exit( main() )
