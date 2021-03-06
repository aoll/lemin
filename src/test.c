 #include "../lemin.h"

int	ft_check_space(char *s);
int	ft_ck_com(char *s);
int	ft_ck_action(char *s);
int	ft_ck_valide_action(char *s);

int	ft_ck_room(char *s);
int	ft_ck_valide_room(char *s);
int	ft_ck_valide_pipe(char *s);

int	ft_ck_error(char *s);
int	ft_vl_first_line(char *s);
int	ft_vl_line(char *s);

void	test_ft_check_space(void)
{
  //check space lign begin return 1 if char * begin by some space
  if (ft_check_space(NULL) != 1)
    printf ("\033[31;01mTEST NULL ft_check_space FAIL..\033[00m\n");
  else if (ft_check_space("") != 1)
    printf ("\033[31;01mTEST 0 ft_check_space FAIL..\033[00m\n");
  else if (ft_check_space(" ok") != 1)
    printf ("\033[31;01mTEST 1 ft_check_space FAIL..\033[00m\n");
  else if (ft_check_space("	ok") != 1)
    printf ("\033[31;01mTEST 2 ft_check_space FAIL..\033[00m\n");
  else if (ft_check_space("\nok") != 1)
    printf ("\033[31;01mTEST 3 ft_check_space FAIL..\033[00m\n");
  else if (ft_check_space("\tok") != 1)
    printf ("\033[31;01mTEST 4 ft_check_space FAIL..\033[00m\n"); 
  else if (ft_check_space("\fok") != 1)
    printf ("\033[31;01mTEST 5 ft_check_space FAIL..\033[00m\n");
  else if (ft_check_space("\rok") != 1)
    printf ("\033[31;01mTEST 6 ft_check_space FAIL..\033[00m\n");
  else if (ft_check_space("ok") == 1)
    printf ("\033[31;01mTEST 7 ft_check_space FAIL..\033[00m\n");
  else
    printf ("TEST ft_check_space \033[32;01mOK\033[00m\n");
  return ;
}

void	test_ft_ck_com(void)
{
  //check # return 1 if char * begin by #
  if (ft_ck_com("#ok") != 1)
    printf ("\033[31;01mTEST 1 ft_ck_com FAIL..\033[00m\n");
  else if (ft_ck_com("ok") == 1)
    printf ("\033[31;01mTEST 1 ft_ck_com FAIL..\033[00m\n");
  else
    //printf ("TEST ft_ck_com \033[32;01mOK\033[00m\n");
   ft_putstr("TEST ft_ck_com \033[32;01mOK\033[00m\n");
  return ;
}

void	test_ft_ck_action(void)
{
  //check if char * begin by ## so ft_ck_action return 1
  if (ft_ck_action("##ok") != 1)
    printf ("\033[31;01mTEST 1 ft_ck_action FAIL..\033[00m\n");
  else if (ft_ck_action("#ok") == 1)
    printf ("\033[31;01mTEST 2 ft_ck_action FAIL..\033[00m\n");
  else if (ft_ck_action("#") == 1)
    printf ("\033[31;01mTEST 3 ft_ck_action FAIL..\033[00m\n");
  else
    printf ("TEST ft_ck_action \033[32;01mOK\033[00m\n");
  return ;
}

void	test_ft_ck_valide_action(void)
{
  //check if action is valide like ##start or ##end, if valide return 1
  if (ft_ck_valide_action("##start") != 1)
    printf ("\033[31;01mTEST 1 ft_ck_valide_action FAIL..\033[00m\n");
  else if (ft_ck_valide_action("##end") != 1)
    printf ("\033[31;01mTEST 2 ft_ck_valide_action FAIL..\033[00m\n");
  else if (ft_ck_valide_action("###start") == 1)
    printf ("\033[31;01mTEST 3 ft_ck_valide_action FAIL..\033[00m\n");
   else if (ft_ck_valide_action("##test") == 1)
    printf ("\033[31;01mTEST 4 ft_ck_valide_action FAIL..\033[00m\n");
  else
    printf ("TEST ft_ck_valide_action \033[32;01mOK\033[00m\n");
  return ;
}

void	test_ft_ck_room(void)
{
  //check if char * is a room, if it's true , return 1;
  if (ft_ck_room("2 4 5") != 1)
    printf ("\033[31;01mTEST 1 ft_ck_room FAIL..\033[00m\n");
  else if (ft_ck_room("a 2 3") != 1)
    printf ("\033[31;01mTEST 2 ft_ck_room FAIL..\033[00m\n");
  else if (ft_ck_room("hfhwikwknk 7899 90") != 1)
    printf ("\033[31;01mTEST 3 ft_ck_room FAIL..\033[00m\n");
   else if (ft_ck_room("jafkn-kjfkjwn") == 1)
    printf ("\033[31;01mTEST 4 ft_ck_room FAIL..\033[00m\n");
   else if (ft_ck_room("3-kjfkjwn") == 1)
     printf ("\033[31;01mTEST 5 ft_ck_room FAIL..\033[00m\n");
   else if (ft_ck_room("1 4 5 6") == 1)
     printf ("\033[31;01mTEST 4 ft_ck_room FAIL..\033[00m\n");
   else
    printf ("TEST ft_ck_room \033[32;01mOK\033[00m\n");
  return ;
}

void	test_ft_ck_valide_room(void)
{
  //check if char * is a valide room, if it's true return 1;
  if (ft_ck_valide_room("2 4 5") != 1)
    printf ("\033[31;01mTEST 1 ft_ck_valide_room FAIL..\033[00m\n");
  else if (ft_ck_valide_room("a 2 3") != 1)
    printf ("\033[31;01mTEST 2 ft_ck_valide_room FAIL..\033[00m\n");
  else if (ft_ck_valide_room("Lhfhwikwknk 7899 90") == 1)
    printf ("\033[31;01mTEST 3 ft_ck_valide_room FAIL..\033[00m\n");
   else if (ft_ck_valide_room("v -4 9") == 1)
    printf ("\033[31;01mTEST 4 ft_ck_valide_room FAIL..\033[00m\n");
   else if (ft_ck_valide_room("3 kjfkjwn ok") == 1)
     printf ("\033[31;01mTEST 5 ft_ck_valide_room FAIL..\033[00m\n");
   else if (ft_ck_valide_room("1 67 9.9") == 1)
     printf ("\033[31;01mTEST 4 ft_ck_valide_room FAIL..\033[00m\n");
   else
    printf ("TEST ft_ck_valide_room \033[32;01mOK\033[00m\n");
  return ;
}

void	test_ft_ck_valide_pipe(void)
{
  //check if char * is a valide pipe, if it's true return 1;
  if (ft_ck_valide_pipe("2-5") != 1)
    printf ("\033[31;01mTEST 1 ft_ck_valide_pipe FAIL..\033[00m\n");
  else if (ft_ck_valide_pipe("2-3 90") != 1)
    printf ("\033[31;01mTEST 2 ft_ck_valide_pipe FAIL..\033[00m\n");
  else if (ft_ck_valide_pipe("L4-6") == 1)
    printf ("\033[31;01mTEST 3 ft_ck_valide_pipe FAIL..\033[00m\n");
   else if (ft_ck_valide_pipe("v-4-9") == 1)
    printf ("\033[31;01mTEST 4 ft_ck_valide_pipe FAIL..\033[00m\n");
   else if (ft_ck_valide_pipe("kjfkjwn-Lok") == 1)
     printf ("\033[31;01mTEST 5 ft_ck_valide_pipe FAIL..\033[00m\n");
   else
    printf ("TEST ft_ck_valide_pipe \033[32;01mOK\033[00m\n");
  return ;
}

void	test_ft_ck_error(void)
{
  //check if char * is a valide pipe, if it's true return 1;
  if (ft_ck_error("2-5") == 1)
    printf ("\033[31;01mTEST 1 ft_ck_error FAIL..\033[00m\n");
  else if (ft_ck_error("5 6 7") == 1)
    printf ("\033[31;01mTEST 2 ft_ck_error FAIL..\033[00m\n");
  else if (ft_ck_error(" L4-6") != 1)
    printf ("\033[31;01mTEST 3 ft_ck_error FAIL..\033[00m\n");
   else if (ft_ck_error("v-4-9") != 1)
    printf ("\033[31;01mTEST 4 ft_ck_error FAIL..\033[00m\n");
   else if (ft_ck_error("kjfkjwn-Lok") != 1)
     printf ("\033[31;01mTEST 5 ft_ck_error FAIL..\033[00m\n");
   else if (ft_ck_error("  kjfkjwn-ok") != 1)
     printf ("\033[31;01mTEST 5 ft_ck_error FAIL..\033[00m\n");
    
 else
    printf ("TEST ft_ck_error \033[32;01mOK\033[00m\n");
  return ;
}

void	test_ft_vl_first_line(void)
{
  //check if the first line is valide,  return 1 if it is true
  if (ft_vl_first_line("25") != 1)
    printf ("\033[31;01mTEST 1 ft_vl_first_line FAIL..\033[00m\n");
    else if (ft_vl_first_line(" 567") == 1)
    printf ("\033[31;01mTEST 2 ft_vl_first_line FAIL..\033[00m\n");
  else if (ft_vl_first_line("5 6 7") == 1)
    printf ("\033[31;01mTEST 2 ft_vl_first_line FAIL..\033[00m\n");
  else if (ft_vl_first_line(" L4-6") == 1)
    printf ("\033[31;01mTEST 3 ft_vl_first_line FAIL..\033[00m\n");
   else if (ft_vl_first_line("#commentaire") == 1)
    printf ("\033[31;01mTEST 4 ft_vl_first_line FAIL..\033[00m\n");
   else if (ft_vl_first_line("kjfkjwn-Lok") == 1)
     printf ("\033[31;01mTEST 5 ft_vl_first_line FAIL..\033[00m\n");
   else if (ft_vl_first_line("  kjfkjwn-ok") == 1)
     printf ("\033[31;01mTEST 5 ft_vl_first_line FAIL..\033[00m\n");
 else
    printf ("TEST ft_vl_first_line \033[32;01mOK\033[00m\n");
}

void	test_ft_vl_line(void)
{
  //check if all the  line is valide, call ft_first_vl_line and ft_ck_error  return 1 if it is true
  if (ft_vl_line("25") != 1)
    printf ("\033[31;01mTEST 1 ft_vl_line FAIL..\033[00m\n");
    else if (ft_vl_line(" 567") == 1)
    printf ("\033[31;01mTEST 2 ft_vl_line FAIL..\033[00m\n");
  else if (ft_vl_line("5 6 7") != 1)
    printf ("\033[31;01mTEST 2 ft_vl_line FAIL..\033[00m\n");
  else if (ft_vl_line(" L4-6") == 1)
    printf ("\033[31;01mTEST 3 ft_vl_line FAIL..\033[00m\n");
   else if (ft_vl_line("#commentaire") != 1)
    printf ("\033[31;01mTEST 4 ft_vl_line FAIL..\033[00m\n");
   else if (ft_vl_line("kjfkjwn-ok") != 1)
     printf ("\033[31;01mTEST 5 ft_vl_line FAIL..\033[00m\n");
   else if (ft_vl_line("  kjfkjwn-ok") == 1)
     printf ("\033[31;01mTEST 5 ft_vl_line FAIL..\033[00m\n");
 else
    printf ("TEST ft_vl_line \033[32;01mOK\033[00m\n");
}

int	main(void)
{
  test_ft_check_space();
  test_ft_ck_com();
  test_ft_ck_action();
  test_ft_ck_valide_action();


  test_ft_ck_room();
  test_ft_ck_valide_room();
  test_ft_ck_valide_pipe();

  test_ft_ck_error();
  test_ft_vl_first_line();
  test_ft_vl_line();
  return (0);
}
