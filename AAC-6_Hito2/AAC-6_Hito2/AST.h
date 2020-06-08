int datos[100];

int globalContadorNum;
char *globalOperacion1;

/* nodes in the abstract syntax tree */ 

struct ast {
   int nodetype;
   struct ast *l;
   struct ast *r;
};

struct numval { 
   int nodetype;
   double number; 
};

struct bucle_while {
  int nodetype;     /* type I or W */
  struct ast *cond; /* condition */
  struct ast *sent; 
};

extern FILE *yyout;

/* build an AST */
  struct ast *newast(int nodetype, struct ast *l, struct ast *r); 
  struct ast *newnum(double d);
  struct ast *new_bucle_while(int nodetype, struct ast *cond, struct ast *sent); 

/* evaluate an AST */ 
  double eval(struct ast *);

/* delete and free an AST */ 
  void treefree(struct ast *);

struct ast * newast(int nodetype, struct ast *l, struct ast *r) {
  struct ast *a = malloc(sizeof(struct ast));
  if(!a) {
    yyerror("out of space");
    exit(0); 
  }
  //printf("NEW AST||||| ");
  a->nodetype = nodetype; a->l = l;
  a->r = r;

  //printf("NEW AST %s ..|| ", a);

  return a;
}

struct ast * newnum(double d) {
  struct numval *a = malloc(sizeof(struct numval));
  if(!a) {
    yyerror("out of space");
    exit(0); 
  }
  a->nodetype = 'K';
  a->number = d;
  //printf("NEW NUM: %s .. %lf ..|| ", a, a->number);

  return (struct ast *)a;
}

double eval(struct ast *a) {
  double v;
  //printf("EVAL||||| ");
  
  switch(a->nodetype) {
    case 'K': v = ((struct numval *)a)->number; 
  break;
    case '+': v = eval(a->l) + eval(a->r); 
  break;
    case '-': v = eval(a->l) - eval(a->r); 
  break;
    case '*': v = eval(a->l) * eval(a->r); 
  break;
    case '/': v = eval(a->l) / eval(a->r); break; 
    case '|': v = eval(a->l); if(v < 0) v = -v; 
  break;
    case 'M': v = -eval(a->l); 
  break;
  /* while do */
  case 'W':
    v = 0.0; /* a default value */
    while( eval(((struct bucle_while *)a)->cond) != 0) 
    {
      v = eval(((struct bucle_while *)a)->sent);
    }
  break;
    default: printf("internal error: bad node %c\n", a->nodetype); 
   }
  return v;
}

struct ast * new_bucle_while(int nodetype, struct ast *cond, struct ast *sent) {
  printf("FLOW||||| ");

  struct bucle_while *a = malloc(sizeof(struct bucle_while));
  if(!a) {
    yyerror("out of space");
    exit(0); 
  }
  a->nodetype = nodetype; 
  a->cond = cond;
  a->sent = sent;
  return (struct ast *)a; 
}


void treefree(struct ast *a) {
  switch(a->nodetype) {
  /* two subtrees */ case '+':
  case '-':
  case '*':
  case '/':
    treefree(a->r);
  /* one subtree */
  case '|':
  case 'M':
    treefree(a->l);

  /* no subtree */
  case 'K':
    free(a);
    break;
  default: printf("internal error: free bad node %c\n", a->nodetype);
  } 
}