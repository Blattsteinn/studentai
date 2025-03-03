
# Performance Test

## Test  1 results

The function **`generate_files(int size)`** generates a file containing **10^size** students. Each student has **n** grades, where **n** is a randomly chosen number between **5 and 12**.

Example of a file:
| Vardas  | Pavarde  | ND1  | ND2  | ... | NDn |
|---------|---------|------|------|-----|-----|
| vardasNr1|PavardeNr1|x|x|x|x|
**Note:** `x` represents a randomly generated number between **1 and 10**.
**Performance Consideration:**
 - The execution time depends on the value of **n**. 
 - If n= 12, the file will take longer to generate compared to smaller values.



### **Results of the test**
| File Name                  | Record Count  | Execution Time (s) |
|----------------------------|--------------|--------------------|
| testavimasFailas1000.txt   | 1,000        | 0.00211           |
| testavimasFailas10000.txt  | 10,000       | 0.01076           |
| testavimasFailas100000.txt | 100,000      | 0.16887           |
| testavimasFailas1000000.txt| 1,000,000    | 1.41491           |
| testavimasFailas10000000.txt| 10,000,000  | 14.8289           |
   
## **Test 2 Results**

(_Content to be added..._)
