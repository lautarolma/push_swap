This project has been created as part of the 42 curriculum by <laviles>.

# 🔄 Push_swap

### Because Swap_push isn’t as natural
### Because Swap_push isn’t as natural

<p align="center">
    <img src="https://img.shields.io/badge/Score-125%2F100-success?style=for-the-badge&logo=42" alt="Score 125/100">
    <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="Language C">
    <img src="https://img.shields.io/badge/Status-Completed-success?style=for-the-badge" alt="Status Completed">
</p>

**Push_swap** is an algorithmic project that involves sorting a stack of data using an auxiliary stack and a limited set of instructions. The main objective is to design and implement an efficient algorithm in C that achieves the sort with the minimum number of operations.

The project focuses on:

* 
**Stack Management**: Implementation of dynamic data structures.


* 
**Algorithm Complexity**: Movement optimization to meet specific performance requirements ( or similar).


* 
**Data Classification**: Implementing sorting logic adapted to specific constraints.



## ⚙️ The Rules

We have two stacks (**a** and **b**) and a specific instruction set:

* 
**Push (`pa`, `pb`)**: Move the top element from one stack to another.


* 
**Swap (`sa`, `sb`)**: Swap the first two elements at the top of a stack.


* 
**Rotate (`ra`, `rb`)**: Shift up all elements by 1; the first becomes the last.


* 
**Reverse Rotate (`rra`, `rrb`)**: Shift down all elements by 1; the last becomes the first.



## 🧠 My Approach (Personal Logic)

I implemented a chunk-based sorting algorithm, commonly known as **k-sort**. This strategy utilizes a **Dynamic Window** that adapts as the sorting progresses, optimizing the number of movements required.

### Advanced Parsing & Memory Management

Unlike common implementations that rely on `ft_strjoin` and `ft_split`, I developed a **custom Tokenizer** approach:

* **Direct Stack Building**: My logic extracts values, validates them, and builds the stack simultaneously.
* **Evolution of Knowledge**: Having recently finished *Get_next_line*, I implemented a "get_next_number" logic. This allowed me to master the use of **static variables** and reinforce my heap memory management and pointer manipulation skills.
* 
**Hybrid Input Support**: The parser is robust enough to handle multiple formats—quoted strings, individual arguments, or mixed inputs —using a custom `strtok` implementation.



## 🛠️ Instructions

### Prerequisites

You need a **Unix-based environment** (Linux/macOS) with `cc` and `make` installed.

### Installation & Usage

1. **Clone & Compile**:
```bash
git clone https://github.com/tu_usuario/push_swap.git && cd push_swap && make

```


2. **Run**:
```bash
./push_swap 3 "2 1" 0

```



## 📚 Resources & Credits

This project is the result of extensive research and logic design. While the code is **entirely my own implementation**, I leveraged the following resources for learning and architectural inspiration:

* **Logic & Strategy:**
* **YouTube:** [Oceano - Push_swap project](https://youtu.be/OaG81sDEpVk?si=JppUGYoOw63sNEax).
* 
**AI Mentorship:** **Gemini** & **ChatGPT** were utilized for strategic tutoring, algorithm conceptualization, and README formatting.




* **Technical References:**
* **Parsing inspiration:** [Aletheios42](https://github.com/Aletheios42).
* **Structural reference:** [7pixeles](https://github.com/7pixeles).
* **Testing tools:** [gumoreno-code](https://github.com/gumoreno-code).


* **Peer Recognition:**
* Special thanks to **manguita** and **daviles** for their mentorship in learning and architectural design.
* Grateful to **alepinto** for his invaluable help in understanding and debugging the `strtok` implementation.





> **Note:** Every line of code was written manually. I used these references to understand best practices, ensuring no "copy-pasting" was involved in the final product.
