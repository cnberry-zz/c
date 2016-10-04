#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>


/* get bit using and with bitshifted mask, compare to zero */
long bitGet(long val, long bit) {
	return (val & (1<<bit)) == 0 ? 0 : 1 ;
}

/* set bit using or with bitshifted mask */
long bitSet(long val, long bit) {
	return val | (1<<bit);
}

int main (int argc, char **argv) {
  long ret = 0, val = 0, bit = 0;
  int c, option_index = 0;
  

  static struct option long_options[] =
    {
      {"set",     required_argument,       NULL, 's'},
      {"get",     required_argument,       NULL, 'g'},
    };

    val = strtol(argv[1],NULL,0);

    c = getopt_long_only (argc, argv, "s:g:",
                       long_options, &option_index);

    switch (c) {
      case 's':
	bit = strtol(optarg,NULL,0);
        ret = bitSet(val,bit);
        break;

      case 'g':
	bit = strtol(optarg,NULL,0);
        ret = bitGet(val,bit);
        break;

      default:
        printf ("Usage: %s <number> -[set|get] args\n",argv[0]);
    }

  printf("input: 0x%lx, setbit: %ld, result: 0x%lx\n",val,bit,ret);
  exit (0);
}
