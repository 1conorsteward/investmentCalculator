# investmentCalculator
This program takes input of initial investment, interest rate, monthly deposit, and time spent in that particular account. 
It will present two charts. 
One with monthly deposits and one without. Both charts show accrued interest over the total time of the investment in incremental stages. 

Below I will answer questions related to this project.

Summarize the project and what problem it was solving...
  -This projects intent was to create a modular program that would calcualte accrued interest over time with a few different variables. Initial deposit, annual interest rate, montly deposit, and the duration of the investment. Two tables are created from these variables. One table includes initial investment with interest rates but leaves out monthly deposits. The other includes all of the variables. Both break down the accrued interest and the resulting balance of the investment on a month to month basis.
  
What did you do particularly well?
  -The code is particularly well modularized. Each class and set of functions is in its own file and keeps the main file clean and small.
  
Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
  -I have no validation input for negative numbers, strange symbols, or otherwise. Classic naming conventions were also not followed, which would be useful for many purposes.
  
Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
  -Figuring out exactly which pieces of the classes should exist in one file or antoher. Making the functions functionality in the .cpp files or putting them in the .h files still puzzles me. Either way works fine BUT ideally they ended up in the .cpp files. Adding github to my support network was useful in asking questions about how exactly my code should be approached and executed.
  
What skills from this project will be particularly transferable to other projects or course work?
  -Modularizing the code will be particularly useful in taking into larger projects to keep them clean and tidy. Also, using classes in multiple usecases was helpful in letting me fully understand how to impliment classes at a larger scale.
  
How did you make this program maintainable, readable, and adaptable?
  -I made this program maintainable by modularizing it well. I made it readable in the same was as well as using naming that makes sense in a readable form. This code is adaptable because it can take any inputs that would make sense in a classic investment sense.
