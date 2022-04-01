[![CodeFactor](https://www.codefactor.io/repository/github/arthurboucard/cpe_bsq/badge)](https://www.codefactor.io/repository/github/arthurboucard/cpe_bsq)

# BSQ

## <img width="26px" src="https://newsroom.ionis-group.com/wp-content/uploads/2018/12/epitech-logo-signature-quadri.png"/> Epitech project :

Algorithm which finds the biggest square in C.

---

### :pencil: Map format description :
• Its first line contains the number of lines on the board (and only that).
<br>
• “.” (representing an empty place) and “o” (representing an obstacle) are the only two characters for the other lines.
<br>
• All of the lines are of the same length (except the first one).
<br>
• It contains at least one line.
<br>
• Each line is terminated by ‘\n’.

#### Exemple of the map:
```
9
...........................
....o......................
............o..............
...........................
....o......................
..............o............
...........................
......o..............o.....
..o.......o................
```

---

### :computer: How to run :
```
./bsq map.txt
```

#### Exemple of output :
```
.....xxxxxxx................
....oxxxxxxx................
.....xxxxxxxo...............
.....xxxxxxx................
....oxxxxxxx................
.....xxxxxxx...o............
.....xxxxxxx................
......o...............o.....
..o.......o.................
```

---

### :exclamation: Rules :
> You can only read from the given files. <br>
> You have to represent only the biggest square. If they are several solutions, choose the square to the left.

---

Made in C
