#include <stdio.h>
#define rep(i,n) for(i=1;i<=n;i++)
int a[101][101], i[101][101];
void
printmat (int a[][101], int dim)
{
  int i, j;
  rep (i, dim)
  {
    rep (j, dim)
    {
      printf ("%d ", a[i][j]);
    }
    printf ("\n");
  }
}

void mult (int a[][101], int b[][101], int dim)
{
  int res[dim + 1][dim + 1], x, y, z;
  rep (x, dim)
  {
    rep (y, dim)
    {
      res[x][y] = 0;
      rep (z, dim) res[x][y] += (a[x][z] * b[z][y]);

    }
  }
  rep (x, dim) rep (y, dim) a[x][y] = res[x][y];
}

void power (int a[][101], int dim, int n)
{
  int x, y, k;
  rep (x, dim) rep (y, dim)
  {
    if (x == y)
      i[x][y] = 1;
    else
      i[x][y] = 0;
  }

  while (n)
    {
      if (n % 2)
	mult (i, a, dim), n--;


      else
	mult (a, a, dim), n /= 2;

    }
  rep (x, dim)
  {
    rep (y, dim)
    {

      a[x][y] = i[x][y];
    }
  }
}
int main ()
{
  int t, dim, n, i, j;
  scanf ("%d", &t);
  while (t--)
    {
      scanf ("%d %d", &dim, &n);
      rep (i, dim) rep (j, dim) scanf ("%d", &a[i][j]);
      power (a, dim, n);
      printmat (a, dim);

    }
return 0;
}
