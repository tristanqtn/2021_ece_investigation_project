# Half Second Semester Project in C

This project, undertaken during the second half of the semester, involves resolving and investigating a C-based shell program. The primary objective is to identify a murderer using only a list of phone calls extracted from the victim's phone. The focus of this mini project lies in working on sorting algorithms and program optimization. Emphasis is placed on addressing complexities, processing times, and finding the most optimized ways to handle the data.

## Technologies Used

- Structures
- Files
- Lists
- Recursivity
- Pointers

## Authors

Code written by Apolline Petit and Tristan Querton for the "Etude de Cas" course under the guidance of Professor M. Segado. The completion date is 18/04/2021.

## Approach and Hypotheses

### Chapter I

For Chapter I, a table of 1000 call structures is used since the number of calls to store is known in advance. Each call's elements (contact, number, call type, etc.) are stored independently in a structure. This structure is then reused in another structure in Chapter II to form a linked list.

### Chapter II

In Chapter II, a linked list is created to traverse the call log only once and create a node for each contact. This list is created from an unsorted list of calls directly read from the "releve.txt" file.

### Chapter III

In Chapter III, a random generation of integers between 0 and 24 inclusive is used (25 possible values, corresponding to the number of suspects). Initially, the same method as for the call histogram is applied. Then, attempts are made to optimize histogram processing using a single for() loop. However, this optimization cannot be applied to structure processing.

## Attention

The provided sorting algorithms are fast, given the small amount of data to process. Consequently, the displayed sorting time may be 0.0000s, 0.0000002s, or even negative values due to a period calculation error. To address this, simply rerun the sorting program.

## Sources

- [GitHub](https://github.com/)
- [cplusplus.com](https://www.cplusplus.com/)
- [101computing](https://www.101computing.net/bubble-sort-vs-insertion-sort/)
- [waytolearnx](https://waytolearnx.com/2019/08/tri-a-bulle-en-c.html)
- [waytolearnx](https://waytolearnx.com/2019/08/tri-par-insertion-en-c.html)
- [waytolearnx](https://waytolearnx.com/2019/08/tri-par-selection-en-c.html)
- [OpenClassrooms](https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c)
- [Developpez.com](https://c.developpez.com/faq/?page=Gestion-des-dates-et-heures#Comment-chronometrer-des-temps-d-execution)

All algorithms used are free of rights and available on the mentioned websites.
