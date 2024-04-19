#include <stdio.h>
#include <string.h>

int main()
{
  float c, f, m;
  char from[3];
  do
  {
    printf("\nFarenheit to Celcius (f-c), Celcius to Farenheit (c-f), Meters to Feet (m-f), Feet to Meters (f-m), Exit (e) : ");
    scanf("%s", &from);
    if (strcmp(from, "f-c") == 0)
    {
      printf("\nEnter the temperatur in the Farenheit scale : ");
      scanf("%f", &f);
      c = (f - 32) * 5 / 9;
      printf("\nThe temperature in celcius is : %.2f", c);
    }

    if (strcmp(from, "c-f") == 0)
    {
      printf("\nEnter the temperatur in the celcius scale : ");
      scanf("%f", &c);
      f = c * 9 / 5 + 32;
      printf("\nThe temperature in Farenheit is : %.2f", f);
    }

    if (strcmp(from, "m-f") == 0)
    {
      printf("\nEnter the length in meters : ");
      scanf("%f", &m);
      f = 3.28 * m;
      printf("\nThe length in feet is : %.2f", f);
    }

    if (strcmp(from, "f-m") == 0)
    {
      printf("\nEnter the length in feet : ");
      scanf("%f", &f);
      m = f / 3.28;
      printf("\nThe length in meters is : %.2f", m);
    }
  } while (strcmp(from, "e") != 0);

  return 0;
}
