#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define maxi 100

typedef struct point{
  double x;
  double y;
}point_t;

typedef struct circle{
  point_t center;
  double radius;
  int giaonhau[maxi], count;
}circle_t;

double giaonh(circle_t a, circle_t b);

void main(void){
  int choice, i, a, n, d, j, max;
  do{
    printf("1. Nhap bang tay\n");
    printf("2. Sinh tu dong\n");
    printf("3. Thoat\n");
    scanf("%d", &choice);
    switch(choice){
    case 1:
      printf("So duong tron muon sinh ra\n");
      scanf("%d", &n);
      circle_t *c = (circle_t*)malloc(n*sizeof(circle_t)) ;
      for(i = 0; i < n; i++){
	printf("Nhap toa do cua duong tron thu %d\n", i+1);
	scanf("%lf%lf", &c[i].center.x, &c[i].center.y);
	printf("Nhap ban kinh cua duong tron thu %d\n", i+1);
	scanf("%lf", &c[i].radius);
	c[i].count = 0;
      }
      for(i = 0; i < n; ++i){
	printf("Duong tron thu %d co tam I%d(%.2lf,%.2lf), Ban kinh R%d = %.2lf\n", i + 1, i + 1, c[i].center.x, c[i].center.y, i + 1, c[i].radius);
      }
      for(i = 0; i < n - 1; i++)
	for(j = i+1 ; j < n; j++)
	  if(giaonh(c[i], c[j]) == 1)
	    {
	      c[i].giaonhau[(c[i].count)] = j + 1;
	      c[j].giaonhau[(c[j].count)] = i + 1;
	      c[i].count++;
	      c[j].count++;
	    }
      for(i = 0; i < n; ++i)
	if(c[i].count > max)
	  max = c[i].count;
      
      for(i = 0; i < n; ++i)
	if(c[i].count == max)
	  {
	    printf("Duong tron thu %d co giao voi tat ca cac duong con lai\n", i + 1);
	    
	    for(j = 0; j < n; ++j)
	      if(c[i].giaonhau[j] > 0){
		printf("vong tron thu %d giao voi vong tron thu %d\n",i + 1, c[i].giaonhau[j]);}
	  }
      free(c);
      break;
      
    case 2:
      srand(time(NULL));
      n=2+rand()%8;
      printf("So duong tron muon sinh ra:%d\n", n);
      circle_t *c1 = (circle_t*)malloc(n*sizeof(circle_t)) ;
      for(i = 0; i < n; i++){
	c1[i].center.x=1+rand()%5;	
	c1[i].center.y=5+rand()%11;
	c1[i].radius=6+rand()%12;
	c1[i].count = 0;
      }
      
	for(i = 0; i < n; ++i)
	  printf("Duong tron thu %d co tam I%d(%.2lf,%.2lf), Ban kinh R%d = %.2lf\n", i + 1, i + 1, c1[i].center.x, c1[i].center.y, i + 1, c1[i].radius);
	
	for(i = 0; i < n - 1; i++)
	  for(j = i+1 ; j < n; j++)
	    if(giaonh(c1[i], c1[j]) == 1)
	      {
		c1[i].giaonhau[(c1[i].count)] = j + 1;
		c1[j].giaonhau[(c1[j].count)] = i + 1;
		c1[i].count++;
		c1[j].count++;
	      }
	for(i = 0; i < n; ++i)
	  if(c1[i].count > max)
	    max = c1[i].count;
	
	for(i = 0; i < n; ++i)
	  if(c1[i].count == max)
	    {
	      printf("Duong tron thu %d co giao voi tat ca cac duong con lai\n", i + 1);
	      
	      for(j = 0; j < n; ++j)
		if(c1[i].giaonhau[j] > 0){
		  printf("vong tron thu %d giao voi vong tron thu %d\n",i + 1, c1[i].giaonhau[j]);}
	    }
	free(c1);
	break;
	
    case 3: printf("ending...\n"); break;
    default: printf("wrong\n");
    }
    
  }while(choice != 3);
}

double giaonh(circle_t a, circle_t b){
  point_t p;
  int s1, s2;
  p.x = (a.center.x - b.center.x);
  p.y = (a.center.y - b.center.y);
  s1 = p.x * p.x + p.y * p.y;
  s2 = (a.radius + b.radius)*(a.radius + b.radius);
  if(s1 < s2)
    return 1;
  else
    return 0;
}














