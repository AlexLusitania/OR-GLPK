/*********************
 * Fancy data reader *
 *********************/

typedef struct {
	int n;
	int ca;
	int *d; // demande de chaque lieu (la case 0 est inutilis�e car le d�p�t n'a aucune demande � voir satisfaire)
	int **C; // distancier (les lignes et colonnes 0 correspondent au d�p�t)
} data;

void please_read_data(char *file, data *p) {

	int i,j;
	FILE *fin;

	int val;
	fin = fopen(file,"rt");

	/* Lecture du nombre de villes */

	fscanf(fin,"%d",&val);
	p->n = val;

	/* Allocation m�moire pour la demande de chaque ville, et le distancier */

	p->d = (int *) malloc (val * sizeof(int));
	p->C = (int **) malloc (val * sizeof(int *));
	for (i = 0; i < val; i++) p->C[i] = (int *) malloc (val * sizeof(int));

	/* Lecture de la capacit� */

	fscanf(fin,"%d",&val);
	p->ca = val;

	/* Lecture des demandes des clients */

	for (i = 1; i < p->n; i++) {

		fscanf(fin,"%d",&val);
		p->d[i] = val;
	}
	
	/* Lecture du distancier */

	for (i = 0; i < p->n; i++) {
		for (j = 0; j < p->n; j++) {

			fscanf(fin,"%d",&val);
			p->C[i][j] = val;
		}
	}

	fclose(fin);
}

/* Fonction de lib�ration m�moire des donn�es */

void please_free_data(data *p) {

	int i;
	for (i = 0; i < p->n; i++) free(p->C[i]);
	free(p->C);
	free(p->d);
}
