# Strategic Investment & Portfolio Manager (C)

A console-based investment analysis system written in **C**, designed to simulate real-world portfolio evaluation using historical price data.  
The program performs **risk and return analysis**, **price range analytics**, and **future investment growth forecasting** using core concepts from statistics, recursion, file handling, and pointer manipulation.

---

## 🚀 Features

- 📊 **Statistical Risk & Return Analysis**
  - Calculates average daily return
  - Measures volatility using standard deviation
  - Classifies assets as:
    - Conservative / Stable
    - Balanced Risk
    - High Volatility

- 📈 **Price Range Analysis**
  - Sorts historical prices using Bubble Sort
  - Identifies minimum, maximum, and total price spread

- 🔮 **Future Growth Forecast**
  - Recursive compound growth calculation
  - Estimates portfolio value over multiple years

- 📂 **File Handling**
  - Loads historical prices from `prices.txt`
  - Automatically generates an investment summary report (`report.txt`)

- 🛡️ **Input Validation**
  - Handles invalid and non-numeric user inputs safely

---

## 🧠 Concepts Demonstrated

- Arrays & Pointer Arithmetic  
- File I/O in C  
- Statistical calculations (mean, variance, standard deviation)  
- Sorting algorithms  
- Recursion  
- Modular programming  
- Defensive input validation  

---

## 🗂️ Project Structure

├── main.c # Core program source code

├── prices.txt # Historical price data (user-provided)

├── report.txt # Auto-generated investment summary

└── README.md


---

## 📝 How to Use

### 1️⃣ Prepare Price Data
Create a file named `prices.txt` in the same directory and add daily prices:

100 102 101.5 104 103

---

### 2️⃣ Compile the Program

```bash
gcc main.c -o investment_manager -lm
```

3️⃣ Run

```bash
./investment_manager
```

📊 Sample Output

```bash
Average Daily Return: 1.84%
Risk Level (Std Dev): 3.12%
Investment Status:   Balanced Risk Asset

```

A detailed summary will also be saved to:

`report.txt`

🎯 Use Cases

    Academic projects (PF / DSA / OOP foundations in C)

    Introductory financial modeling

    Risk analysis simulations

    Practice for file handling & recursion in C

⚠️ Limitations

    Assumes clean numerical data in prices.txt

    Uses Bubble Sort (intentionally simple for learning)

    Not intended for real financial decision-making

📌 Future Improvements

    CSV support

    Dynamic memory allocation

    Advanced sorting algorithms

    Monte Carlo simulations

    Graphical visualization (via external tools)

👤 Author

    Wali
    Built as a learning-focused investment analytics system combining programming fundamentals with financial logic.
