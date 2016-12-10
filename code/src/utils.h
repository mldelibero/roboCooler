#ifndef __UTILS_H
#define ifndef __UTILS_H

///@{
/// @brief Changes an infinite while loop to run once during unit testing
#ifdef IN_TEST_MODE
#define WHILE(j) for(int i = 1; i < 2; i++)

#else
#define WHILE(j) while(j)
#endif
///@}

#endif //#ifndef __UTILS_H
