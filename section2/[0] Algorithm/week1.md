เป็นวิชาออกเเบบโปรเเกรม เเละวิธีไม่เน้นการเขียนโปรเเกรม

### criteria

| list             | score |
| ---------------- | ----- |
| midterm          | 30    |
| final            | 35    |
| quiz             | 20    |
| Lab + grader     | 10    |
| present in class | 5     |

### คำอธิบายรายวิชา

เช็คว่าโค้ดรันถูกไหม
เช็คเวลา
เช็คพื้นที่

เป็นวิชาที่เราจะต้องหาวิธีการทำให้โปรเเกรมรันได้ไว หรือใช้ทรัพยากรที่ถูกต้อง โดยจะมีเรื่องของคณิตศาสตร์มาเกี่ยวข้อง เเละเราจะใช้ template บางเทคนิค เพื่อออกเเบบวิธีการใหม่

<hr>

### ทำไมเราต้องเรียนวิชานี้
เรียนเพื่อให้โปรเเกรมที่รันได้ถูก เเละรันได้ไวขึ้น ด้วย `algo ที่ดี`

<hr>

### การดูว่า algo ดีหรือไม่
ดูที่ Time complexity analysis in `theoretical analysis`

`Theoretical analysis` เป็นเวลาที่นับรอบการทำงาน เมื่อ input = n 

ที่เราต้องใช้เเบบนี้เพราะเป็นเวลาที่เป็นกลางไม่ depend on hardware.

#### Running time estimation
- การวัดประสิทธิภาพด้านเวลา
- Elementary operation counting
- Basic operation counting 
- best case and worst case and average case


### Elementary operation counting 

```ts
1 Algo power( i , n ) {
2   product = 1;
3  for (  i = 1; i < n; i++ ) {
4    product = product * i;
5  }
6  return product;
}
```

เราจะเอามาเขียนตารางของเเต่ละบรรทัด

| Line  | Time  | Repetitions|
|---|---| --- |
| 1  |  t1 | 1 |
| 2  |  t2 | 1 |
| 3  |  t3 | n + 1 |
| 4  |  t4 | n |
| 5  |  t5 | n  |
| 6  |  t6 | 1  |

จากนั้นเรามาเขียน time function $T(n) = \Sigma_{i = 1} ^ m (Time_i * Repetitions_i)$

$T(n) = t1 + t2 + (n+1)t3 + (n)t4 + (n)t5 + t6$

เราจะได้สมการเพื่อเอาไป plot graph ได้


### Basic operation counting 

1. วิเคราะห์จาก operation ในสุด
2. operation นั้นจะต้องขึ้นอยู่กับ input

### Best-case, Average-case, Worst-case Analysis
เป็น Algorithm สำหรับหาจำนวนรอบที่ขึ้นอยู่กับรูปเเบบข้อมูล เช่น sequential search การหาข้อมูลใน array

```ts
Sequential_search (A[ ], K ) {
  i = 0;
  while (A[i] != K && i < A.length ) {
    i += 1;
  }

  if ( i < A.length ) return A[i];
}

```

$B(n)  = 1$ เป็นกรณีเคสเเรก
$W(n) = n$ เป็นกรณีเคสสุดท้าย
$A(n) = \Sigma_{i=1}^n \frac i n$ เป็นจำนวนรอบเฉลี่ย ๆ ของจำนวนรอบของทุก input









