# Bank Management System (OOP - CLI)

A comprehensive, desktop-based Banking Management System operating via a Command Line Interface (CLI). This project was built using **C++** with a strict adherence to **Object-Oriented Programming (OOP)** principles. It is designed to demonstrate clean code architecture, separation of concerns, and robust data persistence using flat text files as a lightweight database.

---

## 🛠️ System Architecture

The application is engineered using a layered architecture to separate the User Interface (UI) from the core business logic:

1. **UI Layer (Screens):** Handled by specialized classes inherited from a base screen component (e.g., `clsMainScreen`, `clsLoginScreen`, `clsTransactionScreen`).
2. **Core Business Logic Layer:** Encapsulated within domain-specific classes handling data manipulation and rules (e.g., `clsBankClient`, `clsUser`, `clsCurrency`).
3. **Data Layer (Persistence):** Manages read/write streams (`fstream`) to maintain records permanently in encrypted/delimited text files.



---

## 🚀 Key Features

### 1. User & Authentication Management
* **Secure Login:** Access control restricted by username and password.
* **Permissions System:** Advanced user management where administrators can grant or deny specific access rights (e.g., full access, manage clients, currency exchange).
* **Login Register Log:** Automatically tracks every login attempt with a timestamp and user details.

### 2. Client Management
* Full CRUD operations: **Create, Read, Update, and Delete** bank clients.
* Automated data validation preventing duplicate Account Numbers.

### 3. Transactions & Banking Operations
* **Deposit & Withdraw:** Secure balance modifications with built-in validation preventing over-drafts or negative inputs.
* **Total Balances:** Real-time summary statistics displaying individual records along with total bank liquidity.
* **Internal Transfers:** Easily transfer funds between accounts with automatic balance adjusting.
* **Transfer Log:** Keeps a persistent record of all transactions (Sender, Receiver, Amount, Balances, User).

### 4. Currency Exchange Engine
* Full currency directory fetching and rate updating.
* **Currency Calculator:** Seamless conversion between international currencies using updated floating-point exchange rates.

---

## 💻 Technical Concepts Applied

* **Object-Oriented Programming (OOP):** Deep implementation of Inheritance, Encapsulation, and Polymorphism.
* **Dynamic Arrays (Vectors):** Utilizing `std::vector` for efficient, in-memory data processing and parsing.
* **File Handling (`fstream`):** Parsing complex raw string records split by custom delimiters (e.g., `//#//`) into structured class objects.
* **Robust Input Validation:** Standardized input sanitization loops preventing software crashes during invalid console data entries.

---

## 📂 Project Structure

```text
├── src/                  # (Highly Recommended Setup) All Source (.cpp) and Header (.h) files
├── data/                 # Text databases (Clients.txt, Users.txt, Currencies.txt)
├── README.md             # Project documentation
└── .gitignore            # Tells Git which files to ignore (Build/IDE files)
