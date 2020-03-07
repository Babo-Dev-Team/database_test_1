#include <stdlib.h>
#include <string.h>
#include <mysql.h>
#include <stdio.h>

int main(int argc, char **argv)
{
  // Mysql data structures
  MYSQL *conn;
  MYSQL_RES *result;
  MYSQL_ROW row;
  
  int err;
  char query[500];

  // create MQYSL server conn
  conn = mysql_init(NULL);
  if(conn == NULL)
    {
      printf("Error while creating the connection: %u, %s\n", mysql_errno(conn), mysql_error(conn));
      exit(1); // exit process with code 1
    }
  
  // init connection
  conn = mysql_real_connect (conn, "localhost","root", "mysql", "BaboGameBBDD", 0, NULL, 0);
  if (conn == NULL) 
  {
	  printf ("Error while initializing connection: %u %s\n", mysql_errno(conn), mysql_error(conn));
	  exit (1);
  }
  
  strcpy(query, "SELECT * FROM jugadors");
  
  err = mysql_query(conn, query);
  if (err != 0)
    {
      printf ("Query Error:  %u %s\n", mysql_errno(conn), mysql_error(conn));
      exit (1);
    }
  result = mysql_store_result(conn);

  row = mysql_fetch_row(result);
  if (row == NULL)
    {
      printf("Query result contains no data\n");
    }
  else
    {
		while (row != NULL)
		{
			printf("%s\t%s\t%s\n", row[0], row[1], row[2]);
			row = mysql_fetch_row(result);
		}
    }
}
