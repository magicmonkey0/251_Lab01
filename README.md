# 251_Lab01
for ENSC 251 Lab 01

## Program description: 
    Simple booking system for a warehouse. 
    Features include reservation, queries, and releasing of storage time slots for loading and unloading goods.

## Assumptions:
    1. The storage periods supported in the system are from Week 1 (starting Jan 1, 2025) to Week 52 (ending Dec 31, 2025)
    2. No reservations can be made during maintenance weeks or peak seasons.
    3. The slot format for each week is in hourly increments, from Slot 0 (midight to 1AM) to Slow 23 (11PM to midnight). Only whole hours.
    4. A reservation in the booking system can only be made in multiples of 2 hours, and it only
    supports same-week reservations. For example, Week 5 Slot 9 to Slot 10 (9 AM to 11 AM) is valid, Week 5 Slot 10 to Slot 13 is also valid, Week 5 Slot 10 to Slot 12 is invalid because it’s not a multiple of 2 hours, Week 4 Slot 20 to Week 5 Slot 2 is invalid because it crosses weeks.


## MISC:
    - make sure code compiles and runs using onlineGDB

---

Due: SUnday September 28th, 2025
People: Maggie Yu and Matthew Mastromonaco
Lab: LA02 Monday 2:30pm