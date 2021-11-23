# Requirements
The calculator has the following keys: 0..9, ., +, -, *, /, ±, =, C, CE and 1-operand keys: 1/x, x2
,
sqrt. In any situation the calculator has to produce a correct result defined by the well known
arithmetic rules. If the calculations is impossible the calculator has to display information helping
the user to resolve the erroneous situation, like:

## Features


- On encountering a division by 0 the display should read "Cannot divide by 0" and typing the
  key “C” should reset the calculator
- On calculating the square root value of a negative operand the display should read "Wrong
  operand".
- On erroneous operand or operation keys the display should read “Reset (C) to continue” or
  “Clear (CE) to continue” as appropriate
  
  ## state to Art
  
  
  Yet to Done
  
  ## 4W and 1H
  
  
  ### what
 - Application that designed to be implemented in local Grocery store or shops. It will helps user to generate invoices for cutomers and also helps in doing calculations
 - Basic functions and exponents. Calculate basic functions such as addition, subtraction, multiplication, and division to solve math problem

  ### Why
  The calculator has the following keys: 0..9, ., +, -, *, /, ±, =, C, CE and 1-operand keys: 1/x, x2
,
sqrt. In any situation the calculator has to produce a correct result defined by the well known
arithmetic rules. If the calculations is impossible the calculator has to display information helping
the user to resolve the erroneous situation, like:

  ### Where
  This application can be implement in local grocery store ,Math problem solve, shops and heavy calculation solve.
  
  ### How
  We may consider a calculator control as a system that reacts to keys performing all elementary
actions. This approach is a dead end street leading to a very complex state machine that is difficult
to handle

  ### Swot Analysis
  
  
  #### Strengths
- Saves Time
- Automatic Calculations
- No chance of errors in calculations of inputs are right

  #### Weakneeses
  - Dependency. Even though calculators can do the basic operations instantly, students should not use it all the time. ...
  - Cheating. The availability of graphic calculators has made it easier for students to cheat during their tests
  
  #### Opertunities
  - Can be implemented in any type of store, shops and collage.
  
  #### Threats
  - Other Similar Applications

  ## High Level Requirements
  
  | HLR    | Description              |
  | -----  | --------------------     |
  | HLR_1  | Do Calculations          |
  | HLR_2  | shop use fast calculation|
  | HLR_3  |  fast calculation        |
  
  ## Low Level Requirements
  
  | LLR HLR_1   |   Description                                                  |
  | ----------  | -------------------------------------------------------------- |
  | LLR_1 HLR_1 |  Get data from standard input                                  |
  | LLR_2 HLR_1 |  Compute the data by doing appropriate peration                |
  | LLR_3 HLR_1 |  Return the amount                                             |
  
  | LLR HLR_2   |  Description                                                              |
  | ----------  | -------------------------------------------------------------- |
  | LLR_1 HLR_2 | Check if user want add calculation                             |
  | LLR_2 HLR_2 | Do the operation on Total amount according to input            |
  | LLR_3 HLR_2 | Return the final amount                                        |
  
  

