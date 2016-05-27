Array.prototype.head = function(){
    if ( !this.length ) return undefined;
    return this[0];
}

function indexModulus( n ) {
    return ( n < 0 ? -( n % 10 ) : n % 10 );
}

/*
function digits( n ) {
    return n.toString()
            .split('')
            .map(Number);
}
*/

function digits(n) {
  
  var recur = function(x,y){
    
    if ( x === 0 ) return y;
    y.unshift(x%10)
    return recur( Math.floor(x/10), y );
  }
  
  return recur( Math.floor(n/10), [n % 10] );
}

function phoneletter(index){
    switch ( indexModulus(index) ){
        case 0:
        case 1:
            return [ " " ];
        case 2:
            return [ "A", "B", "C" ];
        case 3:
            return [ "D", "E", "F" ]
        case 4:
            return [ "G", "H", "I" ]
        case 5:
            return [ "J", "K", "L" ]
        case 6:
            return [ "M", "N", "O" ]
        case 7:
            return [ "P", "Q", "R", "S" ]
        case 8:
            return [ "T", "U", "V" ]
        case 9:
            return [ "W", "X", "Y", "Z" ]
    }
}

function cartesian(arr){
    return arr.reduce(function(a,b){
        return a.map(function(x){
            return b.map(function(y){
                return x.concat(y);
            })
        }).reduce(function(a,b){ return a.concat(b) },[])
    }, [[]])
}

function Phoneword( n ){
    
    return cartesian( digits(n).map(function(digit){
        return phoneletter(digit);
    }))
        .map( function(word){
            return word.join("");
        } );
}
