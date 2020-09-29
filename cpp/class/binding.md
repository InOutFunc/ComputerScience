https://www.geeksforgeeks.org/early-binding-late-binding-c/

 

What: Binding refers to the process of converting identifiers (such as variable and performance names) into addresses.

 

object: Binding is done for each variable and functions.

Functions: matching the call with the right function definition by the compiler

 

Time: It takes place either at compile time or at runtime.

 

 

**Early Binding (compile-time time polymorphism)**: compiler (or linker) directly associate an address to the function call.

 

**Late Binding (Run time polymorphism)**:  the compiler adds code that identifies the kind of object at runtime then matches the call with the right function definition

 

https://www.geeksforgeeks.org/virtual-functions-and-runtime-polymorphism-in-c-set-1-introduction/

class Employee { 

public: 

virtual void raiseSalary() 

{ 

/* common raise salary code */

} 

 

virtual void promote() 

{ 

/* common promote code */

} 

}; 

 

class Manager : public Employee { 

virtual void raiseSalary() 

{ 

/* Manager specific raise salary code, may contain 

increment of manager specific incentives*/

} 

 

virtual void promote() 

{ 

/* Manager specific promote */

} 

}; 

 

// Similarly, there may be other types of employees 

 

// We need a very simple function 

// to increment the salary of all employees 

// Note that emp[] is an array of pointers 

// and actual pointed objects can 

// be any type of employees. 

// This function should ideally 

// be in a class like Organization, 

// we have made it global to keep things simple 

void globalRaiseSalary(Employee* emp[], int n) 

{ 

for (int i = 0; i < n; i++) 

 

// Polymorphic Call: Calls raiseSalary() 

// according to the actual object, not 

// according to the type of pointer 

emp[i]->raiseSalary(); 

} 