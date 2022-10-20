
# define A 0x201923
# define B 0xffffff
# define C 0xfcff5d
# define D 0x7dfc00
# define E 0x0ec434
# define F 0x228c68
# define G 0x8ad8e8
# define H 0x235b54
# define I 0x29bdab
# define J 0x3998f5
# define K 0x37294f
# define L 0x277da7
# define M 0x3750db
# define N 0xf22020
# define O 0x991919
# define P 0xffcba5
# define Q 0xe68f66
# define R 0xc56133
# define S 0x96341c
# define T 0x632819
# define U 0xffc413
# define V 0xf47a22
# define W 0x2f2aa0
# define X 0xb732cc
# define Y 0x772b9d
# define Z 0xf07cab
# define AA 0xd30b94
# define AB 0xedeff3
# define AC 0xc3a5b4
# define AD 0x946aa2
# define AE 0x5d4c86


/*static int	colour(int n)
{
	if (n >= 25)
		return (LEMONCHIFFON);
	if (n  5)
		return (HOTPINK);
	if (n  7)
		return (FIREBRICK);
	if (n  9)
		return (BLUE);
	if (n  2)
		return (GRAY);
	if (n  11)
		return (GREEN);
	if (n  13)
		return (PURPLE);
	if (n  15)
		return (RED);
	if (n  17)
		return (ALICEBLUE);
	if (n  19)
		return (CORAL);
	if (n  21)
		return (WHITE);
	else
		return (BLACK);
	return (0);
}*/
/*
t_palette	*get_palettes(void)
{
	static t_palette	array[5];

	array[0] =
		(t_palette){5, 0, {0x7F1637, 0x047878, 0xFFB733, 0xF57336, 0xC22121}};
	array[1] =
		(t_palette){5, 0, {0x0D1C33, 0x17373C, 0x2B6832, 0x4F9300, 0xA1D700}};
	array[2] =
		(t_palette){5, 0, {0x002F2F, 0x046380, 0xEFECCA, 0xA7A37E, 0xE6E2AF}};
	array[3] =
		(t_palette){7, 10, {0xFF0000, 0xFFFF00, 0x00FF00, 0x00FFFF,
			0x0000FF, 0xFF00FF, 0xFF0000}};
	array[4] = (t_palette){0, 0, {0}};
	return (array);
}
*/

/*
static int	colour(int n)
{
	if (n >= 25)
		return (BLACK);
	if (n < 1)
		return (HOTPINK);
	if (n < 2)
		return (HOTPINK);
	if (n < 3)
		return (HOTPINK);
	if (n < 4)
		return (HOTPINK);
	if (n < 5)
		return (HOTPINK);
	if (n < 6)
		return (HOTPINK);
	if (n < 7)
		return (FIREBRICK);
	if (n < 8)
		return (HOTPINK);
	if (n < 9)
		return (BLUE);
	if (n < 10)
		return (HOTPINK);
	if (n < 11)
		return (GREEN);
	if (n < 12)
		return (HOTPINK);
	if (n < 13)
		return (PURPLE);
	if (n < 14)
		return (HOTPINK);
	if (n < 15)
		return (RED);
	if (n < 16)
		return (HOTPINK);
	if (n < 17)
		return (ALICEBLUE);
	if (n < 18)
		return (HOTPINK);
	if (n < 19)
		return (CORAL);
	if (n < 20)
		return (HOTPINK);
	if (n < 21)
		return (WHITE);
	else
		return (LEMONCHIFFON);
	return (0);
}*/
/*
static int	colour(int n)
{
	if (n >= 31)
		return (BLACK);
	//if (n < 1)
	//	return (WHITE);
	//if (n < 2)
	//	return (B);
	if (n < 3)
		return (C);
	if (n < 4)
		return (D);
	if (n < 5)
		return (E);
	if (n < 6)
		return (F);
	if (n < 7)
		return (G);
	if (n < 8)
		return (H);
	if (n < 9)
		return (I);
	if (n < 10)
		return (J);
	if (n < 11)
		return (K);
	if (n < 12)
		return (L);
	if (n < 13)
		return (M);
	if (n < 14)
		return (N);
	if (n < 15)
		return (O);
	if (n < 16)
		return (P);
	if (n < 17)
		return (Q);
	if (n < 18)
		return (E);
	if (n < 19)
		return (S);
	if (n < 20)
		return (T);
	if (n < 21)
		return (U);
	if (n < 22)
		return (V);
	if (n < 23)
		return (W);
	if (n < 24)
		return (X);
	if (n < 25)
		return (Y);
	if (n < 26)
		return (Z);
	if (n < 27)
		return (AA);
	if (n < 28)
		return (AB);
	if (n < 29)
		return (AC);
	if (n < 30)
		return (AD);
	else
		return (AE);
	return (0);
}*/




t_map    create_map(char *file_name, int height, int width)
{
    int        i;
    t_map    map;
    char    *line;
    int        fd;
    int        gnl_ret;

    i = 0;
    line = NULL;
    gnl_ret = 1;
    map = get_map(height, width);
    fd = open(file_name, O_RDONLY, 0);
    if (fd < 0)
        exit_fd();
    while (gnl_ret == 1)
    {
        gnl_ret = get_next_line(fd, &line);
        if (word_counter(line, ' ') != 0)
            put_value(map[i++], line);
        free_line(line);
    }
    gnl_ret = get_next_line(fd, &line);
    if (gnl_ret == -1)
        print_errors(5);
    free_line(line);
    close(fd);
    return (map);
}

