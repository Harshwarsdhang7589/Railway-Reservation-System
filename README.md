   #                              **Railway Rservation System**

#### Introduction:
This Railway Rservation System which is being built by @Harshwardhan Gaikwad using the C++ Programming Language and implementation of Object Oriented Programming.This Reservation System  which allows the User and Admin in between Communication By automation using logical cases and Automating the system in such a way that, it allows users to Create an account,book regular and prime Membership Tickets,View Transaction history,and it ensures the Security and File management.

   It inherits multiple classes across several files,each file handling a secifi function and working of the Reservation System. 
   _______________________________________________________________________________
### Each File working:
1.**CreateAccount.cpp** – Class: UserAccount 
    Member variable: name, age, gender, work, dob, contact, OTP.
    Method(): constructor, generateOTP, getOTP, saveToFile.

2.**RegularAccount.cpp** – RegularAccount class
Functio(): train setup, destination/seat selection, fare calculation, payment/receipt.

3.**PrimeAccount.cpp** – PrimeAccount class
Inherits from UserAccount for extra features, handles discounts, prime login, notifications.

4.**History.cpp** – RecordHistory, Transaction, PrimeRegistration structs/classes
Function(): load/parse histories, print stats, extract statistics

5.**Security.cpp** – To check Ticket Duplication, safe list Management

6.**freeMemory.cpp** – For cleaning up any dynamic allocations and file streams upon exit.   
__________________________________________________________________________________________________________________________________________________________________________
### Features
1.**Account Creation**:The user's can sign up by entering personal details. The system generates a unique OTP based on prime digits and stores user data in a local file.
2.**Regular Ticket Booking** :ticket:: It allows users to select a destination, Train Type(General/AC), seat type, and calculates faree with  :smile: **Discount** for gender and work status **Gov/NonGov**.

3.:credit_card:**Prime Membership**: It provides a :dollar:**Premium Ticket** pass for frequent travelers, with login, additional discounts, and special notifications.

4.**Transaction History**: It has logs and analyzes transaction data, showing daily toatl transactions and monthly fares collected.

5.**Security**: It checks for duplicate ticket or prime card codes before confirming actions, helping prevent fraud:fire:.

6.**Memory Management**:cd:: This File free's all the  dynamic memory and safely closes file streams to avoid leaks or data loss.
__________________________________________________________________________________________________________________________________________________________________________
#### Files Skeleton:


|  **Railway Reservation System**                 |
|---------------------------------------|
|├── Main.cpp               # Main entry point (contains main())
├── CreateAccount.h   
├── RegularAccount.h  
├── PrimeAccount.h    
├── History.h         
├── Security.h        
├── freeMemory.h      
├── CreateAccount.cpp    # UserAccount class (user management, OTP, file IO)
├── RegularAccount.cpp   # RegularAccount class (book tickets, fares)
├── PrimeAccount.cpp     # PrimeAccount class (membership, extra discounts)
├── History.cpp          # RecordHistory class, structs (transactions/primes, 
├── Security.cpp         # Security class (duplicate code checking)
├── freeMemory.cpp       # MemoryManager class (resource cleanup, file safety)
_________________________________________________________________________________

#### **Output**:
1.**Start** system:To create an account and also provide all  user details;  and auto OTP Generated.
2.**After Successful**: Book a regular ticket? Enter details, see receipt printed.
3.**After Successful**: Register Prime Pass? Provide OTP, receive extra benefits and notifications.
4.**After Successful**:At exit,  the system will  prints transaction summaries and keeps data safe for the next session.
___________________________________________________________________________________




  




