# Quiz1

## item1

Professor teacher gives template of linked list and YOU have to write insertBefore() and deleteNode() function;

input

| line | input  |
|---|---|
|  1 |  number of linklist size |
|  2 |  set of number( s ) to be element |
|  3 -> lineOf( q ) - 1 | operation |
|  lineOf( q ) | end |


operation
| operation  | meaning  |
|---|---|
| i `post` `data`  |  insert `data` before index( `post` ) and `printAllElement( )`  |
| d `data`  | delete node that value = `data` then<br> `printAllElement( )` <br> and display <br>"`data` is deleted" or <br>"`data` not existed" |
|q|end process|


   

___
<ins>case1</ins>

input
``` c++
3
1 2 3
q
```

output 
``` c++
// this case no output but this is elements in linklist
// 3 -> 2 -> 1
```

___
<ins>case2</ins>

input
``` c++
3
1 2 3
i 1 4
i 10 5
q
```

output 
``` c++
4 -> 3 -> 2 -> 1
4 -> 3 -> 2 -> 1 -> 5
```

___
<ins>case3</ins>

input
``` c++
3
1 2 3
i 1 4
i 10 5
d 4
q
```

output 
``` c++
4 -> 3 -> 2 -> 1
4 -> 3 -> 2 -> 1 -> 5
4 is deleted
3 -> 2 -> 1 -> 5
```

---

## item2 : parenthesis

similar problem : [valid parenthesis](https://leetcode.com/problems/valid-parentheses)

use stack to check match of bracket .
(`<<` `>>`) this is not bracket.

input

| line | input  |
|---|---|
|  1 |  string |

operation
| operation  | meaning  |
|---|---|
| e `data`  |  push `data`   |
| d   | pop|
| x   | end process|

case
| input                | output                     |
| -------------------- | -------------------------- |
| (x+y))               | not matched <br> 1 matched |
| (x+y)                | 1 matched                  |
| [ x = 1 ] { ( yy } ) | not matched <br> 1 matched |
| [ ] { ( } )          | not matched                |
| <<>>                 | 0 matched                  |
| < >                  | 1 matched                  |


--- 
## item3

circular queue size = 5


operation
| operation  | meaning  |
|---|---|
| e `data`  |  enqueue `data` and r++  <br> if queue full log <br> "Queue Full"|
| d   | dequeue and f++ if queue empty <br> "Queue Empty"|
| x   | end process|

case 1 

input

input
``` c++
e 10
e 20 
e 30
e 40 
e 50
```

output
``` c++
10 f:2 r:2
20 f:2 r:3
30 f:2 r:4
40 f:2 r:0
50 f:2 r:1
```

---
case 2 | 
-------



input
``` c++
e 10
e 20 
e 30
e 40 
e 50
d
d
d
d
d
x
```

output
``` c++
10 f:2 r:2
20 f:2 r:3
30 f:2 r:4
40 f:2 r:0
50 f:2 r:1
10 f:3 r:1
20 f:4 r:1
30 f:0 r:1
40 f:1 r:1
50 f:2 r:1
```

case3

input
``` c++
e 10
e 20 
e 30
e 40 
e 50
e 60
d
d
d
d
d
d
x
```

output
``` c++
10 f:2 r:2
20 f:2 r:3
30 f:2 r:4
40 f:2 r:0
50 f:2 r:1
Queue Full
10 f:3 r:1
20 f:4 r:1
30 f:0 r:1
40 f:1 r:1
50 f:2 r:1
Queue Empty
```