# Desugar

CPSC-439 Theory of Computation

Team members:
- Brian Lucero (just me)

## CONTENTS: 

### desugar.cpp
- Written in C++
- compiled using `clang++ -std=c++17 desugar.cpp -o desugar`
  - no warnings, or errors when compiled
- Completed the implementation for IF, LOOKUP1, LOOKUP2
- Used Professor Avery's starter code for "symbolic execution" approach

### desugar (executable)
- runs via terminal command: `./desugar`

## OUTPUT

```
temp_1 = NAND(I[1],I[1])
temp_2 = NAND(X[2],temp_1)
temp_3 = NAND(X[3],I[1])
temp_4 = NAND(temp_2,temp_3)
temp_5 = NAND(I[1],I[1])
temp_6 = NAND(X[0],temp_5)
temp_7 = NAND(X[1],I[1])
temp_8 = NAND(temp_6,temp_7)
temp_9 = NAND(I[0],I[0])
temp_10 = NAND(temp_8,temp_9)
temp_11 = NAND(temp_4,I[0])
temp_12 = NAND(temp_10,temp_11)
```
https://github.com/13rianlucero/Desugar/commit/ca5df2e8ff20ddb90ccd31d5b661ef0bd04b8ef7#commitcomment-68010546

https://user-images.githubusercontent.com/47013770/156864140-75ecadd8-d685-4d31-aa73-a0c9c42a8402.jpeg
