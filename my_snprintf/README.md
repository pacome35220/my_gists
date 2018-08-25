Implementation of a "high-level" snprintf() function
---------------


```C
int main()
{
             char *str = my_snprintf("Name: %s, Age: %d, GPA:  %0.2f, best language: %c", "Pacôme", 18, 3.65, 'C');

             printf("%s\n", str);
             return 0;
}
```

...will print "Name: Pacôme, Age: 18, GPA: 3.65, best language: C". 
