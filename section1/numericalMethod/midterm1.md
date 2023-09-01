### midterm : numerical method

1. write program to find answer with graphical method;
### 2. answer the question 

``` js

const f = (x) => {
  return 1 - 2 * x;
}

const error = ( old, new )  => {
  return math.abs( f(old) - f(new) / f(new) );
}

let e = 0.000001
let xl = 0;
let xr = 100;
let xl;
let er;
let iter = 0;

do {
  xm = ( xr + xl ) / 3;

  if ( f(xm) * f(xl) > 0 ) {
    xl = xm;
    er = error( xl, xm );
  } else {
    xr = xm;
    er = error( xl, xm );
  }

  iter++;
  console.log( iter, er, xm, f(xm) );
} while ( er < e )

```
 2.1 what is result when iter = 3

2.2 what is form of f(x) = 0

2.3 Will this function find answer

3.  $f(x) = e^{-x/4} * (2 - x) - 1$

use one point iteration to find value x at iteration 5

|  iteration | x  |
|---|---|
| 1  |  1 |
| 2  |  0.7159746 |
| 3  |  0.8039869 |

$$
\begin{bmatrix}
  15  & -1 & 1 \\
  -3  & 29 & 2 \\
  -4  & -5 & 7 \\
\end{bmatrix}
\begin{Bmatrix}
  x1 \\
  x2 \\
  x3 \\
\end{Bmatrix} =
\begin{Bmatrix}
  4000 \\
  1200 \\
  2350
\end{Bmatrix}
$$

5. solve matrix by
  
5.1 Crammer Rule

5.2 inersion method

5.3 lu decompose