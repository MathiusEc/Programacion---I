# Programming I - Exercise Repository 📚

Welcome to my Programming I repository! This collection contains all the assignments, projects, and exercises completed during the course at UDLA (Universidad de Las Américas).

Made with love for my future self and anyone who might find this repository useful 💙

---

## 📂 Repository Structure

### 🔍 **Algoritmos** (Algorithms)
Common algorithms and data structure implementations in C.

### 📁 **Archivos** (File Management)
File handling projects and data persistence systems.

### 🎓 **Clases** (Class Materials)
Code examples, exercises, and materials from class sessions.

### 💡 **Ejercicios** (Exercises)
Various programming challenges and practice problems.

### 🏗️ **Ejercicios_Estructuras** (Structure Exercises)
Advanced struct-based projects and implementations.

### 👉 **Ejercicios_Punteros** (Pointer Exercises)
Pointer manipulation and memory management exercises.

---

## 🚀 How to Use

### Prerequisites
- **GCC Compiler** (MinGW for Windows, GCC for Linux/Mac)
- **Terminal/Command Prompt**
- Basic knowledge of C programming

### Compilation

#### Single File Programs
```bash
gcc filename.c -o output_name
./output_name
```

#### Multi-File Projects (e.g., Football System)
```bash
gcc futbol.c f_futbol.c -o futbol
./futbol
```

#### For Windows with MinGW
```powershell
gcc filename.c -o filename.exe
.\filename.exe
```

### Running the Football League System

1. Navigate to the `Archivos` folder
2. Compile the project:
   ```bash
   gcc futbol.c f_futbol.c -o futbol
   ```
3. Run the program:
   ```bash
   ./futbol
   ```
4. Follow the menu options:
   - **1**: Initialize teams
   - **2**: Initialize players
   - **3**: Show leaderboard (sorted by points)
   - **4**: Show players
   - **5**: Register a match
   - **6**: Show top scorers table
   - **7**: Exit

The system uses binary files (`equipos.dat`, `jugadores.dat`, `partidos.dat`) to persist data between sessions.

---

## 📝 Key Features by Project

### Football League System
- ✅ Team management with points, goals, and matches played
- ✅ Player tracking with individual goal statistics
- ✅ Match registration with goal scorers
- ✅ Automatic leaderboard sorting
- ✅ Top scorers table (ranked by goals)
- ✅ Binary file persistence
- ✅ Data validation and error handling

### Structure-Based Projects
- Contact management with CRUD operations
- Medical record systems
- Sales tracking and reporting

### Algorithm Implementations
- Sorting algorithms (Bubble sort)
- Search algorithms (Linear search)
- Array manipulations (Rotation, frequency counting)

---

## 🛠️ Technologies Used

- **Language**: C
- **Compiler**: GCC
- **File I/O**: Binary file operations
- **Data Structures**: Structs, arrays, nested structures
- **Concepts**: Functions, pointers, file handling, sorting algorithms

---

## 📚 Learning Objectives

This repository demonstrates proficiency in:
- Structured programming in C
- Memory management and pointers
- File input/output operations
- Data structure implementation
- Algorithm design and analysis
- Modular code organization
- Problem-solving and logic development

---

## 🤝 Contributing

Feel free to use this code for learning purposes. If you find any bugs or improvements, suggestions are welcome!

---

## 📄 License

This is an educational project. Feel free to use and learn from it.

---

## 💫 Credits

Created with dedication during Programming I course at UDLA.

Made with 💙 for learning and growth.

![Link](https://i.pinimg.com/736x/09/d8/d8/09d8d8e6e412188de35a34f9ea7a00fe.jpg)

### *Ramona Flowers*

---

**Note**: All data files (`.dat`) are generated automatically when running the programs. Make sure to initialize teams and players before registering matches in the Football League System.
