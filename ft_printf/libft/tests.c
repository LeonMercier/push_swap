/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:27:17 by lemercie          #+#    #+#             */
/*   Updated: 2024/05/22 13:01:16 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>

char	test_strmapi_a(unsigned int i, char c)
{
	(void) i;
	return (c + 1);
}

char	test_strmapi_b(unsigned int i, char c)
{
	if (i > 0)
		return (c + 1);
	return (c);
}

void	test_striteri_a(unsigned int i, char *c)
{
	(void) i;
	*c = *c + 1;
}

void	test_striteri_b(unsigned int i, char *c)
{
	if (i > 0)
		*c = *c + 1;		
}

void	test_list_print(void *s)
{
	printf("%s\n", (char *) s);
}

void	*test_list_allcaps(void *s)
{
	char	*result;
	int		i;

	if (!((char *) s))
		return (0);
	result = ft_strdup((const char *) s);
	i = 0;
	while (result[i])
	{
		result[i] = ft_toupper(result[i]);
		i++;
	}
	return ((void *) result);
}

void	test_list_del_content(void *c)
{
	free(c);
}

int	main(void)
{
	char	abc_a[] = {"abcdef"};
	char	abc_b[] = {"abcdef"};
//	char	xyz[] = {"XYZZY"};
//	char	abc_c[] = {"abcdef"};
//	char	abc_d[] = {"abcdef"};
//	size_t	sta;
//	size_t	stb;
	char	abc_e[16] = {"abcdef"};
//	char	abc_f[16] = {"abcdef"};
	char	bc[] = {"bc"};

	printf("%s\n", "=== Tests ===");

	printf("%s\n", "=== isalpha ===");
	printf("c == 65: %i - %i\n", ft_isalpha(65), isalpha(65));
	printf("c == 48: %i - %i\n", ft_isalpha(48), isalpha(48));

	printf("%s\n", "=== isdigit ===");
	printf("c == 48: %i - %i\n", ft_isdigit(48), isdigit(48));	
	printf("c == 58: %i - %i\n", ft_isdigit(58), isdigit(58));	

	printf("%s\n", "=== isalnum ===");
	printf("c == 48: %i - %i\n", ft_isalnum(48), isalnum(48));
	printf("c == 58: %i - %i\n", ft_isalnum(58), isalnum(58));

	printf("%s\n", "=== isascii ===");
	printf("c == 48: %i - %i\n", ft_isascii(48), isascii(48));	
	printf("c == 128: %i - %i\n", ft_isdigit(128), isdigit(128));	

	printf("%s\n", "=== isprint ===");
	printf("c == 48: %i - %i\n", ft_isprint(48), isprint(48));	
	printf("c == 31: %i - %i\n", ft_isprint(31), isprint(31));	

	printf("%s\n", "=== strlen ==="); 
	printf("c == Hello: %zu - %zu\n", ft_strlen("Hello"), strlen("Hello"));	
	printf("c == "": %zu - %zu\n", ft_strlen(""), strlen(""));
	// system function segfaults on NULL argument

	printf("%s\n", "=== memset ===");
	char	woop[] = {"WoopWoop"};
	printf("b = woop: %s - %s\n", ft_memset(woop, 90, 3), memset(woop, 90, 3));
	printf("b = woop: %s - %s\n", ft_memset(woop, 90, 3), memset(woop, 90, 3));
	// system function segfaults on NULL argument

	printf("%s\n", "=== bzero ===");
	char	miau[] = {"Meowzi"};
	char	miau2[] = {"Meowzi"};
	ft_bzero(miau, 1);
	bzero(miau2, 1);
	printf("s = miau: %s - %s\n", &miau[0], &miau2[0]);
	printf("s = miau: %s - %s\n", &miau[1], &miau2[1]);

	printf("%s\n", "=== memcpy ===");
//	char	str_memcpy_a[] = {"WoopWoop"};
	char	dst_memcpy_a[] = {"abcdef"};
	char	dst_memcpy_b[] = {"abcdef"};
	ft_memcpy(dst_memcpy_a, "potato", 3);
	memcpy(dst_memcpy_b, "potato", 3);
	printf("Woop->abc: %s - %s\n", dst_memcpy_a, dst_memcpy_b);

	printf("%s\n", "=== memmove ===");
	char	dst_memmove_a[] = {"abcdef"};
	char	dst_memmove_b[] = {"abcdef"};
	ft_memmove(dst_memmove_a, "potato", 3);
	memmove(dst_memmove_b, "potato", 3);
	printf("Xyz->abc: %s - %s\n", dst_memmove_a, dst_memmove_b);
	ft_memmove(&dst_memmove_a[2], dst_memmove_a, 4);
	memmove(&dst_memmove_b[2], dst_memmove_b, 4);
	printf("abc->abc: %s - %s\n", dst_memmove_a, dst_memmove_b);

	printf("%s\n", "=== strlcpy ===");
	char	t_strlcpy_a[] = "Hello";
	char	t_strlcpy_b[] = "Hello";
	//char	*t_strlcpy_c;
	size_t	t_strlcpy_size_a;
	size_t	t_strlcpy_size_b;
	t_strlcpy_size_a = ft_strlcpy(t_strlcpy_a, "boop", 0);
	t_strlcpy_size_b = strlcpy(t_strlcpy_b, "boop", 0);
	printf("dstsize=0: %zu-%s\n", t_strlcpy_size_a, t_strlcpy_a);
	printf("dstsize=0: %zu-%s\n", t_strlcpy_size_b, t_strlcpy_b);
	// test for memory that doestn have a string in it yet
	char	*t_strlcpy_dest_a;
	char	*t_strlcpy_dest_b;
	t_strlcpy_dest_a = malloc(sizeof(char) *15);
	t_strlcpy_dest_b = malloc(sizeof(char) *15);
	t_strlcpy_size_a = ft_strlcpy(t_strlcpy_dest_a, "lorem ipsum dolor sit amet", 15);
	t_strlcpy_size_b = strlcpy(t_strlcpy_dest_b, "lorem ipsum dolor sit amet", 15);
	printf("%zu-%s\n", t_strlcpy_size_a, t_strlcpy_dest_a);
	printf("%zu-%s\n", t_strlcpy_size_b, t_strlcpy_dest_b);
	// segfault if src is NULL
	// segfault if dst is NULL and size > 0

	printf("%s\n", "=== strlcat ===");
	char	dst_strlcat_a[16] = {"abcdef"};
	char	dst_strlcat_b[16] = {"abcdef"};
	size_t	size_strlcat_a;
	size_t	size_strlcat_b;
	size_strlcat_a = ft_strlcat(dst_strlcat_a, "Hello", 16);
	size_strlcat_b = strlcat(dst_strlcat_b, "Hello", 16);
	printf("xyz->abc: %zu-%s - %zu-%s\n", size_strlcat_a, dst_strlcat_a,
			size_strlcat_b, dst_strlcat_b);

	char	*t_strlcat_dest_c = (char *) malloc(sizeof(char) * 15);
	char	*t_strlcat_dest_d = (char *) malloc(sizeof(char) * 15);
	memset(t_strlcat_dest_c, 0, 15);
	memset(t_strlcat_dest_c, 'r', 6);
	memset(t_strlcat_dest_d, 0, 15);
	memset(t_strlcat_dest_d, 'r', 6);
	size_t	t_strlcat_size_a;
	size_t	t_strlcat_size_b;
	t_strlcat_size_a = ft_strlcat(t_strlcat_dest_c, "lorem ipsum", 15);
	t_strlcat_size_b = strlcat(t_strlcat_dest_d, "lorem ipsum", 15);
	printf("%zu-%s\n", t_strlcat_size_a, t_strlcat_dest_c);
	printf("%zu-%s\n", t_strlcat_size_b, t_strlcat_dest_d);
	
	memset(t_strlcat_dest_c, 0, 15);
	memset(t_strlcat_dest_c, 'r', 6);
	t_strlcat_size_a = ft_strlcat(t_strlcat_dest_c, "lorem ipsum dolor sit amet", 1);
	memset(t_strlcat_dest_d, 0, 15);
	memset(t_strlcat_dest_d, 'r', 6);
	t_strlcat_size_b = strlcat(t_strlcat_dest_c, "lorem ipsum dolor sit amet", 1);
	printf("dstsize < actual length of string in dst: %zu-%s", t_strlcat_size_a,
		   	t_strlcat_dest_c);
	printf(" --- %zu-%s\n", t_strlcat_size_b, t_strlcat_dest_d);
	
	t_strlcat_dest_c = (char *) malloc(sizeof(char) * 15);
	bzero(t_strlcat_dest_c, 15);
	t_strlcat_dest_c[0] = 'A';
	t_strlcat_size_a = ft_strlcat(t_strlcat_dest_c, "boh", -1);
	printf("dstsize==-1: %zu-%s --- ", t_strlcat_size_a, t_strlcat_dest_c);
	t_strlcat_dest_c = (char *) malloc(sizeof(char) * 15);
	bzero(t_strlcat_dest_c, 15);
	t_strlcat_dest_c[0] = 'A';
	t_strlcat_size_a = strlcat(t_strlcat_dest_c, "boh", -1);
	printf("%zu-%s\n", t_strlcat_size_a, t_strlcat_dest_c);

	printf("dst==NULL && dstsize==0: %zu - %zu\n", ft_strlcat(NULL, "boh", 0),
			strlcat(NULL, "boh", 0));
//segfault if src is null
// segfault if dst is null and size > 0

	printf("%s\n", "=== toupper ===");
	printf("a->A: %c - %c\n", ft_toupper('a'), toupper('a'));
	printf("A->A: %c - %c\n", ft_toupper('A'), toupper('A'));
	printf("%s\n", "=== tolower ===");
	printf("a->a: %c - %c\n", ft_tolower('a'), tolower('a'));
	printf("A->a: %c - %c\n", ft_tolower('A'), tolower('A'));
	
	printf("%s\n", "=== strchr ===");
	char	strchr_xyz[] = {"XYZZY"};
	printf("Z: %s - %s\n", ft_strchr(strchr_xyz, 'Z'), strchr(strchr_xyz, 'Z'));
	// segfault on null pointer
	
	printf("%s\n", "=== strrchr ===");
	char	strrchr_xyz[] = {"XYZZY"};
	printf("Z: %s - %s\n", ft_strrchr(strrchr_xyz, 'Z'), strrchr(strrchr_xyz, 'Z'));
	// segfault on null pointer
	
	printf("%s\n", "=== strncmp ===");
	printf("equal: %i - %i\n", ft_strncmp(abc_a, abc_b, 6), strncmp(abc_a, abc_b, 6));
	printf("unequal %i - %i\n", ft_strncmp(abc_a, woop, 6), strncmp(abc_a, woop, 6));
	printf("unequal %i - %i\n", ft_strncmp(woop, abc_a, 6), strncmp(woop, abc_a, 6));
	printf("unsigned char: %i - %i\n", ft_strncmp("test\200", "test\0", 6), 
			strncmp("test\200", "test\0", 6));
	printf("s1==NULL, size==0: %i - %i\n", ft_strncmp(NULL, "lol", 0), 
			strncmp(NULL, "lol", 0));
	printf("s2==NULL, size==0: %i - %i\n", ft_strncmp("lol", NULL,  0), 
			strncmp("lol", NULL, 0));
	printf("both==NULL, size==0: %i - %i\n", ft_strncmp(NULL, NULL, 0), 
			strncmp(NULL, NULL, 0));
	// segfault conditions
//	strncmp(NULL, "lol", 3);
//	ft_strncmp(NULL, "lol", 3);
//	strncmp("lol", NULL, 3);
//	ft_strncmp("lol", NULL, 3);
//	strncmp(NULL, NULL, 3);
//	ft_strncmp(NULL, NULL, 3);
	
	printf("%s\n", "=== memchr ===");
	char	memchr_xyz[] = {"XYZZY"};
	printf("Z: %s - %s\n", ft_memchr(memchr_xyz, 'Z', 5), memchr(memchr_xyz, 'Z', 5));
	// must not segfault
	memchr(NULL, 'Z', 0);
	ft_memchr(NULL, 'Z', 0);
// segfault condition
//	memchr(NULL, 'Z', 1);
//	ft_memchr(NULL, 'Z', 1);

	printf("%s\n", "=== memcmp ===");
	printf("equal: %i - %i\n", ft_memcmp(abc_a, abc_b, 6), memcmp(abc_a, abc_b, 6));
	printf("unequal %i - %i\n", ft_memcmp(abc_a, woop, 6), memcmp(abc_a, woop, 6));
	printf("unequal %i - %i\n", ft_memcmp(woop, abc_a, 6), memcmp(woop, abc_a, 6));
	printf("NULL: %i - %i\n", ft_memcmp(NULL, abc_b, 0), memcmp(NULL, abc_b, 0));
	printf("NULL: %i - %i\n", ft_memcmp(abc_a, NULL, 0), memcmp(abc_a, NULL, 0));
	printf("NULL: %i - %i\n", ft_memcmp(NULL, NULL, 0), memcmp(NULL, NULL, 0));
// segfault conditions
//	memcmp(abc_a, NULL, 1);
//	memcmp(NULL, abc_a, 1);
//	memcmp(NULL, NULL, 1);
//	ft_memcmp(abc_a, NULL, 1);
//	ft_memcmp(NULL, abc_a, 1);
//	ft_memcmp(NULL, NULL, 1);

	printf("%s\n", "=== strnstr ===");
	printf("no match: %s - %s\n", ft_strnstr("Hello", "miau", 6), 
			strnstr("Hello", "miau", 6));
	printf("match: %s - %s\n", ft_strnstr(abc_e, bc, 6), strnstr(abc_e, bc, 6));
	char	*empty = (char *) "";
	printf("empty haystack, empty needle, len=-1, match system?: %d\n",
			ft_strnstr(empty, "", -1) == strnstr(empty, "", -1));
	printf("empty haystack, empty needle, len=0, match system?: %d\n",
			ft_strnstr(empty, "", 0) == strnstr(empty, "", 0));
	char	miauw[] = "miauw";
	printf("same pointer, match system?: %d\n", ft_strnstr(miauw, miauw, 5) ==
			strnstr(miauw, miauw, 5));
	printf("%s - %s\n", strnstr("Hello", "lo", 5), ft_strnstr("Hello", "lo", 5));
	printf("%s - %s\n", strnstr(NULL, "lo", 0), ft_strnstr(NULL, "lo", 0));

	// segfault
//	printf("%s\n", strnstr("Hello", NULL, 0));
//	segfault
//	printf("%s\n", strnstr(NULL, "lo", 5));
//	segfault
//	printf("%s\n", strnstr("Hello", NULL, 5));
//	segfault
//	printf("%s\n", strnstr(NULL, NULL, 5));
//	segfault
//	printf("%s\n", strnstr(NULL, NULL, 0));

	printf("%s\n", "=== atoi ===");
	printf("42: %d - %d\n", ft_atoi("42"), atoi("42"));
	printf("-42: %d - %d\n", ft_atoi("-42"), atoi("-42"));
	printf("--42: %d - %d\n", ft_atoi("--42"), atoi("--42"));
	printf("-42a: %d - %d\n", ft_atoi("-42a"), atoi("-42a"));
	printf("+-43: %d - %d\n", ft_atoi("+-43"), atoi("+-43"));
	printf("-+44: %d - %d\n", ft_atoi("-+44"), atoi("-+44"));
	printf("++45: %d - %d\n", ft_atoi("++45"), atoi("++45"));
	printf("+46: %d - %d\n", ft_atoi("+46"), atoi("+46"));
	printf("a+47: %d - %d\n", ft_atoi("a+47"), atoi("a+47"));
	printf("   +48: %d - %d\n", ft_atoi("   +48"), atoi("   +48"));
	printf("49: %d - %d\n", ft_atoi("\t\n\r\v\f +48"), atoi("\t\n\r\v\f +48"));
	printf("50: %d - %d\n", ft_atoi("\016 50"), atoi("\016 50"));
	printf("empty string: %d - %d\n", ft_atoi(""), atoi(""));
	printf("INT_MAX: %d - %d\n", ft_atoi("2147483647"), atoi("2147483647"));
	printf("INT_MAX + 1: %d - %d\n", ft_atoi("2147483648"), atoi("2147483648"));
	printf("INT_MIN: %d - %d\n", ft_atoi("-2147483648"), atoi("-2147483648"));
	printf("INT_MIN - 1: %d - %d\n", ft_atoi("-2147483649"), atoi("-2147483649"));
	printf("Giant: %d - %d\n", ft_atoi("666666666666"), atoi("666666666666"));
	printf("Giant: %d - %d\n", ft_atoi("666666666666666"), atoi("666666666666666"));
	printf("Giant: %d - %d\n", ft_atoi("666666666666666666"),
			atoi("666666666666666666"));
	printf("Giant: %d - %d\n", ft_atoi("666666666666666666666"),
			atoi("666666666666666666666"));
	printf("-Giant: %d - %d\n", ft_atoi("-6666666666666666666666666666666"),
			atoi("-6666666666666666666666666666666"));
	
	//segfault
//	atoi(NULL);

	printf("%s\n", "=== calloc ===");
	void	*ptr_a = ft_calloc(2, 4);
	void	*ptr_b = calloc(2, 4);
	printf("empty: %s - %s\n", (char *) ptr_a, (char *) ptr_b);
	free(ptr_a);
	free(ptr_b);

	printf("%s\n", "=== strdup ===");
	char	*str_ft_strdup = ft_strdup("Hello");
	char	*str_strdup = strdup("Hello");
	printf("Hello: %s - %s\n", str_ft_strdup, str_strdup);
	free(str_ft_strdup);
	free(str_strdup);

	printf("%s\n", "=== FUNCTIONS NOT MATCHING SYSTEM EXACTLY ===");
	printf("%s\n", "=== substr ===");
	printf("%s - %s\n", "ell", ft_substr("Hello", 1, 3));
	printf("%s - %s\n", "lo", ft_substr("Hello", 3, 3));
	printf("empty: %s\n", ft_substr("Hello", 6, 3));
	printf("empty: %s\n", ft_substr("Hello", 1, 0));
	printf("return empty string: %s\n", ft_substr("", 0, 0));
	printf("return empty string: %s\n", ft_substr("", 0, 1));
	printf("return empty string: %s\n", ft_substr("", 1, 1));
	printf("return empty string: %s\n", ft_substr("ARGH", 4, 0));
	printf("return empty string: %s\n", ft_substr("ARGH", 4, 20));
	printf("return empty string: %s\n", ft_substr("ARGH", 5, 20));

	
	printf("%s\n", "=== strjoi ===");
	printf("%s - %s\n", "Good Day", ft_strjoin("Good ", "Day"));

	printf("%s\n", "=== strtrim ===");
	printf("%s - %s\n", "hehe.Hoho", ft_strtrim(",hehe.Hoho,.", ",."));
	printf("empty string: %s\n", ft_strtrim("", ",."));
	printf("empty trimset: ,hehe.Hoho,.: %s\n", ft_strtrim(",hehe.Hoho,.", ""));
	printf("string consists only of trimset: %s\n", ft_strtrim(",.,...,.,.,.", ",."));
	

	printf("%s\n", "=== split ===");

	char	**split_a;
	split_a = ft_split("miau,meow,wololo,aaaaa", ',');
	while (*split_a)
	{
		printf("%s - ", *split_a);
		split_a++;
	}
	printf("\n");
	
	char	**split_b;
	split_b = ft_split(",mi,me,wo,as", ',');
	while (*split_b)
	{
		printf("%s - ", *split_b);
		split_b++;
	}
	printf("\n");

	char	**split_c;
	split_c = ft_split(",miau,meow,wololo,aaaaa,", ',');
	while (*split_c)
	{
		printf("%s - ", *split_c);
		split_c++;
	}
	printf("\n");

	char	**split_d;
	split_d = ft_split("miau,meow,,wololo,aaaaa", ',');
	while (*split_d)
	{
		printf("%s - ", *split_d);
		split_d++;
	}
	printf("\n");

	printf("empty string: ");
	char	**split_e;
	split_e = ft_split("", ',');
	while (*split_e)
	{
		printf("%s - ", *split_e);
		split_e++;
	}
	printf("\n");

	printf("string only has separators: ");
	char	**split_f;
	split_f = ft_split(",,,,,,,,", ',');
	while (*split_f)
	{
		printf("%s - ", *split_f);
		split_f++;
	}
	printf("\n");

	printf("only on word at end: ");
	char	**split_g;
	split_g = ft_split(",,,,,,,,miau", ',');
	while (*split_g)
	{
		printf("%s - ", *split_g);
		split_g++;
	}
	printf("\n");
	
	printf("hello!: ");
	char	**split_h;
	split_h = ft_split("hello!zzzzzzzz", 'z');
	while (*split_h)
	{
		printf("%s - ", *split_h);
		split_h++;
	}
	printf("\n");
	
	printf("%s\n", "=== itoa ===");
	printf("42: %s\n", ft_itoa(42));
	printf("-42: %s\n", ft_itoa(-42));
	printf("0: %s\n", ft_itoa(0));
	printf("INT_MIN: %s\n", ft_itoa(INT_MIN));
	printf("INT_MAX: %s\n", ft_itoa(INT_MAX));
	printf("1000: %s\n", ft_itoa(1000));

	printf("%s\n", "=== strmapi ===");
	printf("char+1, Ifmmp: %s\n", ft_strmapi("Hello", test_strmapi_a));
	printf("if i > 0: char+1, Hfmmp: %s\n", ft_strmapi("Hello", test_strmapi_b));
	
	printf("%s\n", "=== striteri ===");
	char	c_striteri_test_a[] = "Hello";
	ft_striteri(c_striteri_test_a, test_striteri_a);
	printf("char+1, Ifmmp: %s\n", c_striteri_test_a);
	char	c_striteri_test_b[] = "Hello";
	ft_striteri(c_striteri_test_b, test_striteri_b);
	printf("if i > 0: char+1, Hfmmp: %s\n", c_striteri_test_b);

	printf("%s\n", "=== putchar_fd ===");
	ft_putchar_fd('A', 1);
	printf("\n");
	ft_putchar_fd('a', open("writetest.tmp", O_WRONLY));
	printf("\n");

	printf("%s\n", "=== putstr_fd ===");
	ft_putstr_fd("Hello", 1);
	printf("\n");
	ft_putstr_fd("Hello", open("writetest1.tmp", O_CREAT | O_WRONLY));
	printf("\n");

	printf("%s\n", "=== putendl_fd ===");
	ft_putendl_fd("Hello", 1);
	printf("\n");
	ft_putendl_fd("Hello", open("writetest2.tmp", O_CREAT | O_WRONLY));
	printf("\n");
	
	printf("%s\n", "=== putnbr_fd ===");
	printf("42:\n");
	ft_putnbr_fd(42, 1);
	printf("\n");
	ft_putnbr_fd(42, open("writetest3.tmp", O_CREAT | O_WRONLY));

	printf("-42:\n");
	ft_putnbr_fd(-42, 1);
	printf("\n");


	printf("%d: \n", INT_MIN);
	ft_putnbr_fd(INT_MIN, 1);
	printf("\n");

	printf("0: \n");
	ft_putnbr_fd(0, 1);
	printf("\n");

	printf("1000: \n");
	ft_putnbr_fd(1000, 1);
	printf("\n");

	printf("%s\n", "=== ft_lstnew ===");
	char	*list_content_a;
	list_content_a = ft_strdup("Hello");
	t_list	*list_start;
	list_start = ft_lstnew(list_content_a);
	printf("%s\n", list_start->content);

	// this doesnt test null list to add to
	// also doesnt test that both pointers are updated
	printf("%s\n", "=== ft_lstadd_front ===");
	char	*list_content_b;
	list_content_b = ft_strdup("Moi");
	t_list	*new_list_start;
	new_list_start = ft_lstnew(list_content_b);
	ft_lstadd_front(&list_start, new_list_start);
	printf("%s\n", new_list_start->content);
	printf("%s\n", new_list_start->next->content);

	printf("%s\n", "=== ft_lstsize ===");
	printf("%i\n", ft_lstsize(new_list_start));
	printf("%i\n", ft_lstsize(0));

	printf("%s\n", "=== ft_lstlast ===");
	printf("%s\n", ft_lstlast(new_list_start)->content);

	// this doesnt test null lists to add to
	printf("%s\n", "=== ft_lstadd_back ===");
	char	*list_content_c;
	list_content_c = ft_strdup("oho");
	t_list	*list_third;
	list_third = ft_lstnew(list_content_c);
	ft_lstadd_back(&new_list_start, list_third);
	printf("%s\n", ft_lstlast(new_list_start)->content);

	// borken
	printf("%s\n", "=== ft_lstdelone ===");
	char	*list_content_d;
	char	*list_content_e;
	char	*list_content_ea;
	list_content_d = strdup("Heh");
	list_content_e = strdup("Wow");
	list_content_ea = strdup("Yea");
	t_list	*list_fourth;
	t_list	*list_fifth;
	t_list	*head_three;
	head_three = ft_lstnew(list_content_ea);
	list_fourth = ft_lstnew(list_content_d);
	list_fifth = ft_lstnew(list_content_e);
	ft_lstadd_back(&head_three, list_fourth);
	ft_lstadd_back(&head_three, list_fifth);
	printf("%i\n", ft_lstsize(head_three));
	ft_lstdelone(list_fourth, test_list_del_content);
	printf("%i\n", ft_lstsize(head_three));
	ft_lstiter(head_three, test_list_print);

	printf("%s\n", "=== ft_lstclear ===");
	ft_lstiter(new_list_start, test_list_print);
	ft_lstclear(&new_list_start, test_list_del_content);
//	ft_lstiter(new_list_start, test_list_print);

	printf("%s\n", "=== ft_lstiter ===");
//	ft_lstiter(new_list_start, test_list_print);

	printf("%s\n", "=== ft_lstmap ===");
	char	*list_content_f;
	char	*list_content_g;
	char	*list_content_h;
	char	*list_content_i;
	char	*list_content_j;
	list_content_f = strdup("Heh");
	list_content_g = strdup("Mi");
	list_content_h = strdup("Ma");
	list_content_i = strdup("Mo");
	list_content_j = strdup("Me");
	t_list	*head_allcaps;
	head_allcaps = ft_lstnew(list_content_f);
	ft_lstadd_back(&head_allcaps, ft_lstnew(list_content_g));
	ft_lstadd_back(&head_allcaps, ft_lstnew(list_content_h));
	ft_lstadd_back(&head_allcaps, ft_lstnew(list_content_i));
	ft_lstadd_back(&head_allcaps, ft_lstnew(list_content_j));
	ft_lstiter(head_allcaps, test_list_print);
	head_allcaps = ft_lstmap(head_allcaps, test_list_allcaps, free);
	ft_lstiter(head_allcaps, test_list_print);


}
