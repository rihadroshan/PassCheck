# Passcheck - Password Strength Evaluator  

Passcheck designed to assess the strength of passwords based on various security criteria. It ensures that passwords meet length requirements and contain a mix of uppercase letters, lowercase letters, numbers, and special characters.  

## Features  

- Validates password length against defined minimum and maximum requirements  
- Checks for the presence of:  
  - Uppercase letters  
  - Lowercase letters  
  - Numbers  
  - Special characters  
- Evaluates and categorizes password strength into four levels: **Weak, Poor, Strong, or Excellent**  

## Installation and Usage  

### 1. Clone the Repository  

To get started, clone the PassCheck repository and navigate into the project directory:  

```bash
git clone https://github.com/rihadroshan/passcheck.git
cd passcheck
```

### 2. Compile the Program  

Compile the C program using `gcc` or any compatible C compiler:  

```bash
gcc -o passcheck passcheck.c
```

### 3. Run the Program  

Execute the compiled binary:  

```bash
./passcheck
```

Follow the on-screen instructions to enter a password and receive an evaluation of its strength.  

## Example Usage  

```
Enter your password: W@li2l8o$2*#
Password is excellent.
```
