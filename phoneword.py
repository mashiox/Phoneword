from itertools import product

class Phoneletter:
    
    def __init__( self ):
        self.table = [ 
            [ 'A', 'B', 'C' ],      # 2
            [ 'D', 'E', 'F' ],      # 3
            [ 'G', 'H', 'I' ],      # 4
            [ 'J', 'K', 'L' ],      # 5
            [ 'M', 'N', 'O' ],      # 6
            [ 'P', 'Q', 'R', 'S' ], # 7
            [ 'T', 'U', 'V' ],      # 8
            [ 'W', 'X', 'Y', 'Z' ], # 9
            [ ' ' ]                 # 0 or 1
        ]
    # END INIT
    
    
    def get( self, index ):
        if ( index < 0 or index > 9 ): raise IndexError("Invalid index value")
        if ( index == 0 or index == 1 ): return self.table[ 8 ]
        return self.table[ index-2 ]
    # END GET 
    
    
    def exists( self, index ):
        if ( index < 0 or index > 9 ): return False
        return True
    # END EXISTS
    
# END PHONELETTER


class Phoneword:
    
    def __init__( self, phoneNumber ):
        self.input = list( map( int, str(phoneNumber) ) )
        self.table = list()
    # END INIT
    
    
    def _computeWords( self ):
        pl = Phoneletter()
        return [
            ''.join( y ) for y in list(
                # note: "*[]" is the splat operator.
                product( *[ pl.get(x) for x in self.input ] )
            )
        ]
    # END _COMPUTEWORDS
    
    
    def __repr__( self ):
        self.table = self._computeWords()
        return '\n'.join( self.table )
    # END REPR
    
    
# END PHONEWORD
  