
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
| Record Count  | Generates in (s) - Test 1 | Generates in (s) - Test 2  | Generates in (s) - Test 3  | Average (s) |
|--------------|----------------------------|----------------------------|----------------------------|-------------|
| 1,000        | 0.00211                     | 0.0022902                   | 0.0022022                   | 0.002201    |
| 10,000       | 0.01076                     | 0.0177911                   | 0.0149421                   | 0.014498    |
| 100,000      | 0.16887                     | 0.13363                     | 0.127824                    | 0.143441    |
| 1,000,000    | 1.41491                     | 1.61177                     | 1.29193                     | 1.439537    |
| 10,000,000   | 14.8289                     | 14.6758                     | 8.42556                     | 12.64342    |

   
## **Test 2 Results**

The function `testing()` evaluates the efficiency of:

1.  **Reading Data from Files**
2.  **Sorting Students by Final Grade**
3.  **Dividing Students into Two Groups**:
    -   Students with a final grade < 5.0
    -   Students with a final grade >= 5.0
4.  **Writing Each Group to a Separate File**

### **Results of the test**

| Record count  | Read Time (s) | Sort Time (s) | Grouping Time (s) | Writing final grade < 5.0 (s) | Writing final grade >= 5.0 (s) | Total Execution Time (s) |
|--------------------------------|--------------|---------------|-------------------|-------------------------|-------------------------|-------------------------|
| 1,000        | 0.0346782    | 0.0014194     | 0.0006414         | 0.0022755               | 0.0016757               | 0.0016757               |
| 10,000     | 0.204569     | 0.0099844     | 0.0093545         | 0.0079479               | 0.0108424               | 0.0108424               |
| 100,000     | 1.94752      | 0.132301      | 0.102911          | 0.0787083               | 0.0941297               | 0.0941297               |
| 1,000,000      | 15.625       | 1.61485       | 0.868594          | 0.536537                | 0.799398                | 0.799398                |
| 10,000,000     | 185.243      | 34.1973       | 17.1692           | 10.172                  | 8.47341                 | 8.47341                 |
