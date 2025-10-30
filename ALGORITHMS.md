# Data Structures Algorithms - Lab Experiments

---

## Experiment 5a: Circular Queue using Arrays

### Aim
To implement a circular queue using arrays with insert, delete and display operations.

### Algorithm
```
1. Start
2. Initialize global variables: FRONT = -1, REAR = -1, MAX, Q[50]
3. Input maximum size from user and store in MAX
4. Display menu with options: Display, Enqueue, Dequeue, Exit
5. Use switch statement to call respective functions based on user choice
6. Repeat until user chooses exit

Function ENQUEUE():
   If ((REAR + 1) % MAX == FRONT) then
      Print "Queue Overflow"
      Return
   End If
   If (FRONT == -1) then
      FRONT = 0
   End If
   REAR = (REAR + 1) % MAX
   Read ITEM
   Q[REAR] = ITEM
   Call DISPLAY()
End Function

Function DEQUEUE():
   If (FRONT == -1) then
      Print "Queue Underflow"
      Return
   End If
   If (FRONT == REAR) then
      FRONT = -1
      REAR = -1
   Else
      FRONT = (FRONT + 1) % MAX
   End If
   Print "Element deleted"
   Call DISPLAY()
End Function

Function DISPLAY():
   If (FRONT == -1) then
      Print "Queue is empty"
      Return
   End If
   I = FRONT
   Print "Queue: "
   While (I != REAR)
      Print Q[I]
      I = (I + 1) % MAX
   End While
   Print Q[I]
End Function

7. Stop
```

### Data Structure Used
Circular Queue (Array-based implementation)

### Result
The program has been successfully executed and output is verified.

---

## Experiment 5b: Circular Queue using Linked List

### Aim
To implement a circular queue using linked list with insert, delete and display operations.

### Algorithm
```
1. Start
2. Initialize global variables: FRONT = NULL, REAR = NULL
3. Define Node structure with DATA and LINK fields
4. Display menu with options: Display, Enqueue, Dequeue, Exit
5. Use switch statement to call respective functions based on user choice
6. Repeat until user chooses exit

Function ENQUEUE():
   Create new node TEMP
   If (TEMP == NULL) then
      Print "Queue Overflow"
      Return
   End If
   Read ITEM
   TEMP->DATA = ITEM
   TEMP->LINK = NULL
   
   If (FRONT == NULL) then
      FRONT = TEMP
      REAR = TEMP
      REAR->LINK = FRONT  // Make circular
   Else
      REAR->LINK = TEMP
      REAR = TEMP
      REAR->LINK = FRONT  // Point rear to front
   End If
   Call DISPLAY()
End Function

Function DEQUEUE():
   If (FRONT == NULL) then
      Print "Queue Underflow"
      Return
   End If
   
   TEMP = FRONT
   If (FRONT == REAR) then  // Only one node
      FRONT = NULL
      REAR = NULL
   Else
      FRONT = FRONT->LINK
      REAR->LINK = FRONT  // Maintain circular link
   End If
   Free TEMP
   Print "Element deleted"
   Call DISPLAY()
End Function

Function DISPLAY():
   If (FRONT == NULL) then
      Print "Queue is empty"
      Return
   End If
   
   TEMP = FRONT
   Print "Queue: "
   Do
      Print TEMP->DATA
      TEMP = TEMP->LINK
   While (TEMP != FRONT)
End Function

7. Stop
```

### Data Structure Used
Circular Queue (Linked List implementation)

### Result
The program has been successfully executed and output is verified.

---

## Experiment 6: Double-Ended Queue (Dequeue)

### Aim
To implement a double-ended queue with operations to insert and delete elements from both front and rear ends.

### Algorithm
```
1. Start
2. Initialize global variables: FRONT = -1, REAR = -1, MAX, Q[50]
3. Input maximum size from user and store in MAX
4. Display menu with options: Display, Push(front), Pop(front), Inject(rear), Eject(rear), Exit
5. Use switch statement to call respective functions
6. Repeat until user chooses exit

Function PUSH():  // Insert at front
   If (FRONT == -1) then
      FRONT = 0
      REAR = 0
      POS = 0
   Else
      If (FRONT == 0) then
         POS = MAX - 1
      Else
         POS = FRONT - 1
      End If
      If (POS == REAR) then
         Print "Queue Overflow"
         Return
      End If
   End If
   FRONT = POS
   Read ITEM
   Q[FRONT] = ITEM
   Call DISPLAY()
End Function

Function POP():  // Delete from front
   If (FRONT == -1) then
      Print "Queue Underflow"
      Return
   End If
   If (FRONT == REAR) then
      FRONT = -1
      REAR = -1
   Else
      FRONT = (FRONT + 1) % MAX
   End If
   Print "Element deleted from front"
   Call DISPLAY()
End Function

Function INJECT():  // Insert at rear
   If ((REAR + 1) % MAX == FRONT) then
      Print "Queue Overflow"
      Return
   End If
   If (FRONT == -1) then
      FRONT = 0
   End If
   REAR = (REAR + 1) % MAX
   Read ITEM
   Q[REAR] = ITEM
   Call DISPLAY()
End Function

Function EJECT():  // Delete from rear
   If (FRONT == -1) then
      Print "Queue Underflow"
      Return
   End If
   If (FRONT == REAR) then
      FRONT = -1
      REAR = -1
   Else If (REAR == 0) then
      REAR = MAX - 1
   Else
      REAR = REAR - 1
   End If
   Print "Element deleted from rear"
   Call DISPLAY()
End Function

Function DISPLAY():
   If (FRONT == -1) then
      Print "Queue is empty"
      Return
   End If
   I = FRONT
   Print "Dequeue: "
   While (I != REAR)
      Print Q[I]
      I = (I + 1) % MAX
   End While
   Print Q[I]
End Function

7. Stop
```

### Data Structure Used
Double-Ended Queue (Array-based circular implementation)

### Result
The program has been successfully executed and output is verified.

---

## Experiment 7: Infix to Postfix Conversion and Evaluation

### Aim
To convert an infix expression to postfix notation using stack and evaluate the postfix expression.

### Algorithm
```
PART A - INFIX TO POSTFIX:

1. Start
2. Initialize global variables: HEAD (stack pointer), POSTFIX[64]
3. Input INFIX expression from user
4. Append ')' to end of INFIX
5. Push '(' onto stack

Function IsOperator(SYMBOL):
   If SYMBOL in {'^', '(', ')', '*', '/', '+', '-'} then
      Return TRUE
   Else
      Return FALSE
   End If
End Function

Function GetPrecedence(OPERATOR):
   If OPERATOR == '^' then Return 4
   If OPERATOR in {'*', '/'} then Return 3
   If OPERATOR in {'+', '-'} then Return 2
   If OPERATOR == '(' then Return 1
   Return 0
End Function

6. For each SYMBOL in INFIX:
   If SYMBOL == '(' then
      Push SYMBOL onto stack
   Else If IsOperator(SYMBOL) == FALSE then
      Append SYMBOL to POSTFIX
   Else If SYMBOL == ')' then
      While (Top of stack != '(')
         Pop from stack and append to POSTFIX
      End While
      Pop '(' from stack
   Else  // SYMBOL is operator
      While (GetPrecedence(Top of stack) >= GetPrecedence(SYMBOL))
         Pop from stack and append to POSTFIX
      End While
      Push SYMBOL onto stack
   End If
End For

7. Print POSTFIX expression
8. Stop

---

PART B - POSTFIX EVALUATION:

1. Start
2. Initialize stack using linked list: HEAD
3. Input POSTFIX expression

Function IsOperator(SYMBOL):
   If SYMBOL in {'^', '*', '/', '+', '-'} then
      Return TRUE
   Else
      Return FALSE
   End If
End Function

Function Evaluate(OP1, OP2, OPERATOR):
   If OPERATOR == '+' then Return OP1 + OP2
   If OPERATOR == '-' then Return OP1 - OP2
   If OPERATOR == '*' then Return OP1 * OP2
   If OPERATOR == '/' then Return OP1 / OP2
   If OPERATOR == '^' then Return OP1 ^ OP2
End Function

4. For each SYMBOL in POSTFIX:
   If IsOperator(SYMBOL) == FALSE then
      Push SYMBOL onto stack
   Else
      OP2 = Pop from stack
      OP1 = Pop from stack
      RESULT = Evaluate(OP1, OP2, SYMBOL)
      Push RESULT onto stack
   End If
End For

5. FINAL_RESULT = Pop from stack
6. Print FINAL_RESULT
7. Stop
```

### Data Structure Used
Stack (Linked List implementation) for conversion and evaluation

### Result
The program has been successfully executed and output is verified.

---

## Experiment 8: Infix to Prefix Conversion

### Aim
To convert an infix expression to prefix notation using stack.

### Algorithm
```
1. Start
2. Initialize global variables: HEAD (stack pointer), PREFIX[64], TEMP[64]
3. Input INFIX expression from user
4. Reverse the INFIX expression and store in TEMP

Function IsOperator(SYMBOL):
   If SYMBOL in {'^', '(', ')', '*', '/', '+', '-'} then
      Return TRUE
   Else
      Return FALSE
   End If
End Function

Function GetPrecedence(OPERATOR):
   If OPERATOR == '^' then Return 4
   If OPERATOR in {'*', '/'} then Return 3
   If OPERATOR in {'+', '-'} then Return 2
   If OPERATOR == ')' then Return 1
   Return 0
End Function

5. For each SYMBOL in TEMP:
   If SYMBOL == '(' then Replace with ')'
   If SYMBOL == ')' then Replace with '('
End For

6. For each SYMBOL in TEMP:
   If SYMBOL == ')' then
      Push SYMBOL onto stack
   Else If IsOperator(SYMBOL) == FALSE then
      Append SYMBOL to PREFIX
   Else If SYMBOL == '(' then
      While (Top of stack != ')')
         Pop from stack and append to PREFIX
      End While
      Pop ')' from stack
   Else  // SYMBOL is operator
      While (Stack not empty AND GetPrecedence(Top) > GetPrecedence(SYMBOL))
         Pop from stack and append to PREFIX
      End While
      Push SYMBOL onto stack
   End If
End For

7. While (Stack not empty)
   Pop from stack and append to PREFIX
End While

8. Reverse PREFIX expression
9. Print PREFIX expression
10. Stop
```

### Data Structure Used
Stack (Linked List implementation)

### Result
The program has been successfully executed and output is verified.

---

## Experiment 9: Searching Algorithms

### Aim
To implement linear search and binary search algorithms.

### Algorithm
```
LINEAR SEARCH:

1. Start
2. Declare: A[50], N, KEY, I

Function LINEAR_SEARCH(A, N, KEY):
   For I = 0 to N-1
      If (A[I] == KEY) then
         Return I
      End If
   End For
   Return -1
End Function

3. Input number of elements N
4. For I = 0 to N-1
      Input A[I]
   End For
5. Input search KEY
6. RESULT = Call LINEAR_SEARCH(A, N, KEY)
7. If (RESULT == -1) then
      Print "Element not found"
   Else
      Print "Element found at index", RESULT
   End If
8. Stop

---

BINARY SEARCH (Recursive):

1. Start
2. Declare: A[50], N, KEY

Function BINARY_SEARCH(A, LOW, HIGH, KEY):
   If (LOW > HIGH) then
      Return -1
   End If
   MID = (LOW + HIGH) / 2
   If (A[MID] == KEY) then
      Return MID
   Else If (KEY < A[MID]) then
      Return BINARY_SEARCH(A, LOW, MID-1, KEY)
   Else
      Return BINARY_SEARCH(A, MID+1, HIGH, KEY)
   End If
End Function

3. Input number of elements N
4. For I = 0 to N-1
      Input A[I]  // Array must be sorted
   End For
5. Input search KEY
6. RESULT = Call BINARY_SEARCH(A, 0, N-1, KEY)
7. If (RESULT == -1) then
      Print "Element not found"
   Else
      Print "Element found at index", RESULT
   End If
8. Stop
```

### Data Structure Used
Array

### Result
The program has been successfully executed and output is verified.

---

*End of Lab Experiments*
