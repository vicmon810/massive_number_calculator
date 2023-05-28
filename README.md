# Rational Thinking:
magically Integer part is finished.


### Test Case :

|Test Case| Test method|Test process | Result|
|:--------|:------------|:-----------|:-------|
|#1.1|Operator += | no sign addition| OK|
|#1.2|Operator +=| one positive sign and one has no sign number addition| OK|
|#1.3|Operator +=|one negative sign and one no sign number addition| OK|
|#1.4|Operator +=|two positive sign number addition| OK|
|#1.5|Operator +=|one positive sign and one negative sign number addition|OK|
|#1.6|Operator +=|two negative sign addition| OK|
|#1.7|Operator +=|one short number and one long number addition|OK|
|#1.8|Operator +=|two long number addition | OK|
|#2.1|Operator -=|no sign subtraction| OK|
|#2.2|Operator -=|A-=B where B > A| OK|
|#2.3|Operator -=|+A -= B|OK|
|#2.4|Operator -=|+A -= +B|OK|
|#2.5|Operator -=|-A -=B|OK|
|#2.6|Operator -=|-A -= -B|OK|
|#2.7|Operator -=|+A -= -B|OK|
|#2.8|Operator -=|-A -= +B|OK|
|#2.8|operator -=|both A and B are long number| OK|
|#3.1|Operator *=|no sign multiple |OK|
|#3.2|Operator *=|-A *= B |OK|
|#3.3|Operator *=|A *= -B| OK|
|#3.4|Operator *=|-A *= -B|OK|
|#3.5|Operator *=|-A *= -B|OK|
|#3.6|Operator *=|-A *= +B|OK|
|#3.7|Operator *=|+A *= -B|OK|
|#3.8|Operator *=|Both A and B are large number|OK|
|#3.9|Operator *=|+A *= +B|OK|
|#4.1|Operator /=|no sign division|OK|
|#4.2|Operator /=|-A /= B |OK|
|#4.3|Operator /=|A /= -B |OK|
|#4.4|Operator /=|A /= -B |OK|
|#4.5|Operator /=|-A /= -B |OK|
|#4.6|Operator /=|+A /= -B|OK|
|#4.7|Operator /=|-A /= -B|OK|
|#4.8|Operator /=|Both A and B are Long number|OK|
|#5.1|Operator %=|no sign remainder| OK|
|#5.2|Operator %=|-A %= B|OK|
|#5.3|Operator %=|A %= -B|OK|
|#5.4|Operator %=|-A %= -B|OK|
|#5.5|Operator %=|+A %= -B|OK|
|#5.6|Operator %=|+A %= +B|OK|
|#5.7|Operator %=|-A %= +B|OK|
|#5.8|Operator %=|+A %= -B|OK|
|#5.9|Operator %=|both A and B are long number|OK|
|#6.1|