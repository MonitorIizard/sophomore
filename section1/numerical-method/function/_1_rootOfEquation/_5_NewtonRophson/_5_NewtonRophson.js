// var math = require("mathjs");

// function f(x) {
//   return math.evaluate("exp(-x/4)*(2-x) - 1", {x});
// }

// function fd(x) {
//   return math.derivative("exp(-x/4)*(2-x) - 1", 'x').evaluate({x});
// }

// let x = 3; //* initial start
// let i = 0; //* iterative
// let es = 0.001 //* stopping critetion tolerance
// let result = []; //* records of each iteration

// while ( true && i <= 100 ) {
//   let xOld = x;
//   let deltaX = - f(x) / fd(x);
//   x = xOld + deltaX;
//   let tol = Math.abs( (x-xOld) / x ) * 100;

//   result.push({i, x, tol});
  
//   if( tol < es ) {
//     break
//   }

//   i++;
// }

// console.log( result );

let prev = [["", ""], ["", ""]];
const next = [...prev];
const value = 3;
if (value > prev.length) {
  for (let i = prev.length; i < value; i++) {
    next.push(Array.from({ length: value }, (_, i) => ""));
  }
} else {
  next.splice(value);
}

console.log( next);

// setAx((prev) => {
//   const next = [...prev];

//   if (value > prev.length) {
//     for (let i = prev.length; i < 5; i++) {
//       next.push(Array.from({ length: value }, () => ""));
//     }
//   } else {
//     next.splice(value);
//   }

//   return next;
// });