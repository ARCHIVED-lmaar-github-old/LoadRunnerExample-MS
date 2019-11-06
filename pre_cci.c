# 1 "c:\\documents and settings\\lmaar\\desktop\\load runner\\myspace\\ms100\\\\combined_MS100.c"
# 1 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/lrun.h" 1
 












 











# 102 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/lrun.h"








































































	

 


















 
 
 
 
 


 
 
 
 
 
 














int     lr_start_transaction   (char * transaction_name);
int lr_start_sub_transaction          (char * transaction_name, char * trans_parent);
long lr_start_transaction_instance    (char * transaction_name, long parent_handle);



int     lr_end_transaction     (char * transaction_name, int status);
int lr_end_sub_transaction            (char * transaction_name, int status);
int lr_end_transaction_instance       (long transaction, int status);


 
typedef char* lr_uuid_t;
 



lr_uuid_t lr_generate_uuid();

 


int lr_generate_uuid_free(lr_uuid_t uuid);

 



int lr_generate_uuid_on_buf(lr_uuid_t buf);

   
# 262 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/lrun.h"
int lr_start_distributed_transaction  (char * transaction_name, lr_uuid_t correlator, long timeout  );

   







int lr_end_distributed_transaction  (lr_uuid_t correlator, int status);


double lr_stop_transaction            (char * transaction_name);
double lr_stop_transaction_instance   (long parent_handle);


void lr_resume_transaction           (char * trans_name);
void lr_resume_transaction_instance  (long trans_handle);


int lr_update_transaction            (const char *trans_name);


 
void lr_wasted_time(long time);


 
int lr_set_transaction(const char *name, double duration, int status);
 
long lr_set_transaction_instance(const char *name, double duration, int status, long parent_handle);


int   lr_user_data_point                      (char *, double);
long lr_user_data_point_instance                   (char *, double, long);
 



int lr_user_data_point_ex(const char *dp_name, double value, int log_flag);
long lr_user_data_point_instance_ex(const char *dp_name, double value, long parent_handle, int log_flag);


int lr_transaction_add_info      (const char *trans_name, char *info);
int lr_transaction_instance_add_info   (long trans_handle, char *info);
int lr_dpoint_add_info           (const char *dpoint_name, char *info);
int lr_dpoint_instance_add_info        (long dpoint_handle, char *info);


double lr_get_transaction_duration       (char * trans_name);
double lr_get_trans_instance_duration    (long trans_handle);
double lr_get_transaction_think_time     (char * trans_name);
double lr_get_trans_instance_think_time  (long trans_handle);
double lr_get_transaction_wasted_time    (char * trans_name);
double lr_get_trans_instance_wasted_time (long trans_handle);
int    lr_get_transaction_status		 (char * trans_name);
int	   lr_get_trans_instance_status		 (long trans_handle);

 



int lr_set_transaction_status(int status);

 



int lr_set_transaction_status_by_name(int status, const char *trans_name);
int lr_set_transaction_instance_status(int status, long trans_handle);


typedef void* merc_timer_handle_t;
 

merc_timer_handle_t lr_start_timer();
double lr_end_timer(merc_timer_handle_t timer_handle);


 
 
 
 
 
 











 



int   lr_rendezvous  (char * rendezvous_name);
 




int   lr_rendezvous_ex (char * rendezvous_name);



 
 
 
 
 
char *lr_get_vuser_ip (void);
void   lr_whoami (int *vuser_id, char ** sgroup, int *scid);
char *	  lr_get_host_name (void);
char *	  lr_get_master_host_name (void);

 
long     lr_get_attrib_long	(char * attr_name);
char *   lr_get_attrib_string	(char * attr_name);
double   lr_get_attrib_double      (char * attr_name);


 
 
static void *ci_this_context = 0;






 








void lr_continue_on_error (int lr_continue);
char *   lr_decrypt (const char *EncodedString);


 
 
 
 
 
 



 






 














void   lr_abort (void);
void lr_exit(int exit_option, int exit_status);
void lr_abort_ex (unsigned long flags);

void   lr_peek_events (void);


 
 
 
 
 


void   lr_think_time (double secs);

 


void lr_force_think_time (double secs);


 
 
 
 
 



















int   lr_msg (char * fmt, ...);
int   lr_debug_message (unsigned int msg_class,
									    char * format,
										...);
# 492 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/lrun.h"
void   lr_new_prefix (int type,
                                 char * filename,
                                 int line);
# 495 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/lrun.h"
int   lr_log_message (char * fmt, ...);
int   lr_message (char * fmt, ...);
int   lr_error_message (char * fmt, ...);
int   lr_output_message (char * fmt, ...);
int   lr_vuser_status_message (char * fmt, ...);
int   lr_error_message_without_fileline (char * fmt, ...);
int   lr_fail_trans_with_error (char * fmt, ...);

 
 
 
 
 
# 518 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/lrun.h"

 
 
 
 
 





int   lr_next_row ( char * table);
int lr_advance_param ( char * param);



														  
														  

														  
														  

													      
 


char *   lr_eval_string (char * str);
int   lr_eval_string_ext (const char *in_str,
                                     unsigned long const in_len,
                                     char ** const out_str,
                                     unsigned long * const out_len,
                                     unsigned long const options,
                                     const char *file,
								     long const line);
# 552 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/lrun.h"
void   lr_eval_string_ext_free (char * * pstr);

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
int lr_param_increment (char * dst_name,
                              char * src_name);
# 575 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/lrun.h"













											  
											  

											  
											  
											  

int	  lr_save_var (char *              param_val,
							  unsigned long const param_val_len,
							  unsigned long const options,
							  char *			  param_name);
# 599 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/lrun.h"
int   lr_save_string (const char * param_val, const char * param_name);


 
 
 
 
 
 
# 664 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/lrun.h"
void   lr_save_datetime (const char *format, int offset, const char *name);









 











 
 
 
 
 






 



char * lr_error_context_get_entry (char * key);

 



long   lr_error_context_get_error_id (void);


 
 
 

int lr_table_get_rows_num (char * param_name);

int lr_table_get_cols_num (char * param_name);

char * lr_table_get_cell_by_col_index (char * param_name, int row, int col);

char * lr_table_get_cell_by_col_name (char * param_name, int row, const char* col_name);

int lr_table_get_column_name_by_index (char * param_name, int col, 
											char * * const col_name,
											int * col_name_len);
# 725 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/lrun.h"

int lr_table_get_column_name_by_index_free (char * col_name);


 
 
 
 
 
 
 
 

 
 
 
 
 
 
int   lr_param_substit (char * file,
                                   int const line,
                                   char * in_str,
                                   int const in_len,
                                   char * * const out_str,
                                   int * const out_len);
# 750 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/lrun.h"
void   lr_param_substit_free (char * * pstr);


 
# 762 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/lrun.h"





char *   lrfnc_eval_string (char * str,
                                      char * file_name,
                                      long const line_num);
# 770 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/lrun.h"


int   lrfnc_save_string ( const char * param_val,
                                     const char * param_name,
                                     const char * file_name,
                                     long const line_num);
# 776 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/lrun.h"

int lr_save_searched_string(char *buffer, long buf_size, unsigned int occurrence,
			    char *search_string, int offset, unsigned int param_val_len, 
			    char *param_name);

 
char *   lr_string (char * str);

 
# 842 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/lrun.h"

int   lr_save_value (char * param_val,
                                unsigned long const param_val_len,
                                unsigned long const options,
                                char * param_name,
                                char * file_name,
                                long const line_num);
# 849 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/lrun.h"


 
 
 
 
 











int   lr_printf (char * fmt, ...);
 
int   lr_set_debug_message (unsigned int msg_class,
                                       unsigned int swtch);
# 871 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/lrun.h"
unsigned int   lr_get_debug_message (void);


 
 
 
 
 

void   lr_double_think_time ( double secs);
void   lr_usleep (long);


 
 
 
 
 
 




int *   lr_localtime (long offset);


int   lr_send_port (long port);


# 947 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/lrun.h"



struct _lr_declare_identifier{
	char signature[24];
	char value[128];
};

int   lr_pt_abort (void);

void vuser_declaration (void);






# 976 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/lrun.h"


# 988 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/lrun.h"
















 
 
 
 
 







int    _lr_declare_transaction   (char * transaction_name);


 
 
 
 
 







int   _lr_declare_rendezvous  (char * rendezvous_name);

 
 
 
 
 

 
int lr_enable_ip_spoofing();
int lr_disable_ip_spoofing();


 




int lr_convert_string_encoding(char *sourceString, char *fromEncoding, char *toEncoding, char *paramName);






# 1 "c:\\documents and settings\\lmaar\\desktop\\load runner\\myspace\\ms100\\\\combined_MS100.c" 2

# 1 "globals.h" 1



 
 

# 1 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/web_api.h" 1







# 1 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/as_web.h" 1





















































 




 








 
 
 

  int
	web_add_filter(
		const char *		mpszArg,
		...
	);									 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int
	web_add_auto_filter(
		const char *		mpszArg,
		...
	);									 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
	
  int
	web_add_auto_header(
		const char *		mpszHeader,
		const char *		mpszValue);

  int
	web_add_header(
		const char *		mpszHeader,
		const char *		mpszValue);
  int
	web_add_cookie(
		const char *		mpszCookie);
  int
	web_cleanup_auto_headers(void);
  int
	web_cleanup_cookies(void);
  int
	web_concurrent_end(
		const char * const	mpszReserved,
										 
		...								 
	);
  int
	web_concurrent_start(
		const char * const	mpszConcurrentGroupName,
										 
										 
		...								 
										 
	);
  int
	web_create_html_param(
		const char *		mpszParamName,
		const char *		mpszLeftDelim,
		const char *		mpszRightDelim);
  int
	web_create_html_param_ex(
		const char *		mpszParamName,
		const char *		mpszLeftDelim,
		const char *		mpszRightDelim,
		const char *		mpszNum);
  int
	web_custom_request(
		const char *		mpszReqestName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_disable_keep_alive(void);
  int
	web_enable_keep_alive(void);
  int
	web_find(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_get_int_property(
		const int			miHttpInfoType);
  int
	web_image(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_image_check(
		const char *		mpszName,
		...);
  int
	web_java_check(
		const char *		mpszName,
		...);
  int
	web_link(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

	
  int
	web_global_verification(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 

  int
	web_reg_find(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										 
										 
				
  int
	web_reg_save_param(
		const char *		mpszParamName,
		...);							 
										 
										 
										 
										 
										 
										 

  int
	web_convert_param(
		const char * 		mpszParamName, 
										 
		...);							 
										 
										 


										 

										 
  int
	web_remove_auto_filter(
		const char *		mpszArg,
		...
	);									 
										 
				
  int
	web_remove_auto_header(
		const char *		mpszHeaderName,
		...);							 
										 



  int
	web_remove_cookie(
		const char *		mpszCookie);

  int
	web_save_header(
		const char *		mpszType,	 
		const char *		mpszName);	 
  int
	web_set_certificate(
		const char *		mpszIndex);
  int
	web_set_certificate_ex(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_set_connections_limit(
		const char *		mpszLimit);
  int
	web_set_max_html_param_len(
		const char *		mpszLen);
  int
	web_set_max_retries(
		const char *		mpszMaxRetries);
  int
	web_set_proxy(
		const char *		mpszProxyHost);
  int
	web_set_proxy_bypass(
		const char *		mpszBypass);
  int
	web_set_secure_proxy(
		const char *		mpszProxyHost);
  int
	web_set_sockets_option(
		const char *		mpszOptionID,
		const char *		mpszOptionValue
	);
  int
	web_set_option(
		const char *		mpszOptionID,
		const char *		mpszOptionValue,
		...								 
	);
  int
	web_set_timeout(
		const char *		mpszWhat,
		const char *		mpszTimeout);
  int
	web_set_user(
		const char *		mpszUserName,
		const char *		mpszPwd,
		const char *		mpszHost);

  int
	web_sjis_to_euc_param(
		const char *		mpszParamName,
										 
		const char *		mpszParamValSjis);
										 

  int
	web_submit_data(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_submit_form(
		const char *		mpszStepName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										  
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
  int
	web_url(
		const char *		mpszUrlName,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int 
	web_set_proxy_bypass_local(
		const char * mpszNoLocal
		);

  int 
	web_cache_cleanup(void);

  int
	web_create_html_query(
		const char* mpszStartQuery,
		...);							 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 
										 

  int 
	web_create_radio_button_param(
				const char *NameFiled,
				const char *NameAndVal,
				const char *ParamName
				);











# 539 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/as_web.h"


# 552 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/as_web.h"



























# 590 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/as_web.h"

 
 
 


  int
	FormSubmit(
		const char *		mpszFormName,
		...);
  int
	InitWebVuser(void);
  int
	SetUser(
		const char *		mpszUserName,
		const char *		mpszPwd,
		const char *		mpszHost);
  int
	TerminateWebVuser(void);
  int
	URL(
		const char *		mpszUrlName);
























# 658 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/as_web.h"



 
 
 









# 9 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/web_api.h" 2













 






 










  int
	web_reg_add_cookie(
		const char *		mpszCookie,
		...);							 
										 

  int
	web_report_data_point(
		const char *		mpszEventType,
		const char *		mpszEventName,
		const char *		mpszDataPointName,
		const char *		mpszLAST);	 
										 
										 
										 

  int
	web_text_link(
		const char *		mpszStepName,
		...);

  int
	web_image_link(
		const char *		mpszStepName,
		...);

  int
	web_static_image(
		const char *		mpszStepName,
		...);

  int
	web_image_submit(
		const char *		mpszStepName,
		...);

  int
	web_button(
		const char *		mpszStepName,
		...);

  int
	web_edit_field(
		const char *		mpszStepName,
		...);

  int
	web_radio_group(
		const char *		mpszStepName,
		...);

  int
	web_check_box(
		const char *		mpszStepName,
		...);

  int
	web_list(
		const char *		mpszStepName,
		...);

  int
	web_text_area(
		const char *		mpszStepName,
		...);

  int
	web_map_area(
		const char *		mpszStepName,
		...);

  int
	web_eval_java_script(
		const char *		mpszStepName,
		...);

  int
	web_reg_dialog(
		const char *		mpszArg1,
		...);

  int
	web_browser(
		const char *		mpszStepName,
		...);

  int
	web_set_rts_key(
		const char *		mpszArg1,
		...);

  int
	web_save_param_length(
		const char * 		mpszParamName,
		...);

  int
	web_save_timestamp_param(
		const char * 		mpszParamName,
		...);

  int
	web_load_cache(
		const char *		mpszStepName,
		...);							 
										 

  int
	web_dump_cache(
		const char *		mpszStepName,
		...);							 
										 
										 

  int
	web_reg_find_in_log(
		const char *		mpszArg1,
		...);							 
										 
										 

  int
	web_get_sockets_info(
		const char *		mpszArg1,
		...);							 
										 
										 
										 
										 





 
 
 





# 7 "globals.h" 2

# 1 "C:\\Program Files\\Mercury Interactive\\Mercury LoadRunner\\include/lrw_custom_body.h" 1
 





# 8 "globals.h" 2







 
 

int x,c,lastx,i,y,z,cyc;
char tmpString[100], lastString[100];

char friendArray[10000][10];

long friendCounter;


int noPages, noFriends, noAdd, noAlready;




# 2 "c:\\documents and settings\\lmaar\\desktop\\load runner\\myspace\\ms100\\\\combined_MS100.c" 2

# 1 "vuser_init.c" 1
 







vuser_init()
{
	friendCounter = 0;
	noPages = 0;
	noFriends = 0;
	noAdd = 0;
	noAlready = 0;

	Login();

	return 0;
}
# 3 "c:\\documents and settings\\lmaar\\desktop\\load runner\\myspace\\ms100\\\\combined_MS100.c" 2

# 1 "Action.c" 1
Action()
{
	MSF01_Friends_Search( "Lauren" );

 

	lr_message( "***!~ COMPLETED Action() ~!***" );

	return 0;
}
# 4 "c:\\documents and settings\\lmaar\\desktop\\load runner\\myspace\\ms100\\\\combined_MS100.c" 2

# 1 "MSF05_Friends_Search_Loop.c" 1
MSF05_Friends_Search_Loop( char *myFriendPages )
{
	int MFP, StartPage, EndPage;

	MFP = (atoi( myFriendPages ) / 10);

	lr_message( myFriendPages );

	sprintf( tmpString, "%s friends, %d pages TOTAL", myFriendPages, MFP );

	lr_message( tmpString );

	 
    srand(time(0));

	StartPage = rand() % (MFP-10);

	sprintf( tmpString, "***!~ Random Start Page = %d", StartPage );
	lr_message( tmpString );

	 
	EndPage = StartPage + 10;

	lr_message( "Debug Point" );

	for( i=StartPage; i<EndPage; i++ )
	{
    	lr_start_transaction("SearchLoop");

		noPages++;

		sprintf( tmpString, "***!~ Search Loop Page = %d", i );
		lr_message( tmpString );

  		sprintf( tmpString, "%d", i );
  		lr_save_string( tmpString, "myFriendPage" );

		lr_message( "Debug Point" );

    	web_add_cookie("MYSPACE=myspace; DOMAIN=www.myspace.com");

    	web_add_cookie("AUTOSONGPLAY=0; DOMAIN=www.myspace.com");

    	web_add_cookie("FRNDID=15537523; DOMAIN=www.myspace.com");

    	 
        web_reg_save_param(
    		"friendID", 
           	"LB=.viewprofile&friendID=",
    		"RB=&Mytoken=", 
    		"ORD=ALL",
    		"LAST");
		 
# 62 "MSF05_Friends_Search_Loop.c"
    	 



    	web_url("index.cfm_3", 
    		"URL=http://www.myspace.com/index.cfm?fuseaction=find&Mytoken={tokenID}&circuitaction=search&searchType=network&f_first_name=lauren&InterestType=&f_search_criteria=&noDetail=0&first=No&Major=&Clubs=&CurrentCourses=&noDetail=0&Country=&distance=-1&Postal=91765&Photos=1&Gender=2&AgeFrom=18&AgeTo=35&Page={myFriendPage}", 
    		"TargetFrame=", 
    		"Resource=0", 
    		"RecContentType=text/html", 
    		"Referer=http://search.myspace.com/index.cfm?fuseaction=find&Mytoken={tokenID}", 
    		"Snapshot=t204.inf", 
    		"Mode=HTML", 
    		"LAST");
     
# 86 "MSF05_Friends_Search_Loop.c"
    	lr_message( lr_eval_string( "{friendID_count}" ) );

    	x = atoi( lr_eval_string( "{friendID_count}" ) );

    	for( c=1; c<x+1; c++ )
    	{
    		sprintf( tmpString, "%d", c );
    		lr_save_string( tmpString, "c" );
    		lr_save_string( lr_eval_string( lr_eval_string( "{friendID_{c}}" ) ), "friendIDstring" );

    		sprintf( tmpString, "%s", lr_eval_string( "{friendIDstring}" ) );

    		lr_message( tmpString );

    		if( c>1 )
    		{
    			if( strcmp( tmpString, lastString ) != 0 )
    			{
    				 
    				sprintf( friendArray[friendCounter++], "%s", tmpString );
    			}
    		}

    		sprintf( lastString, "%s", tmpString );
    	}

    	lr_message( lr_eval_string( "{friendPages}" ) );

    	sprintf( tmpString, "%lu", friendCounter );

    	lr_message( tmpString );

		for( c=0; c<friendCounter; c++ )
		{
			sprintf( tmpString, "%d - %s", c, friendArray[c] );
			lr_message( tmpString );
		}

		for( c=0; c<friendCounter; c++ )
		{
			sprintf( tmpString, "%d - %s", c, friendArray[c] );
			lr_message( tmpString );

			sprintf( tmpString, "***!~ Search Loop Page = %d, Friend Count = %d", i, c );
			lr_message( tmpString );

          	MSF10_Friends_Add( friendArray[c] );

			noFriends++;
		}

     
# 148 "MSF05_Friends_Search_Loop.c"

     
# 161 "MSF05_Friends_Search_Loop.c"
     
# 194 "MSF05_Friends_Search_Loop.c"
    	lr_end_transaction("SearchLoop",2);

    	lr_think_time(3);

		lr_message( "***!~ COMPLETED LOOP ~!***" );

		for( c=0; c<friendCounter; c++ )
		{
			sprintf( tmpString, "%d - %s", c, friendArray[c] );
			lr_message( tmpString );
		}

		friendCounter=0;
	}

	return 0;
}
# 5 "c:\\documents and settings\\lmaar\\desktop\\load runner\\myspace\\ms100\\\\combined_MS100.c" 2

# 1 "Login.c" 1
Login()
{

	web_add_cookie("DERDB=ZG9tYWluPWhvdG1haWwmdGxkPWNvbSZzbW9rZXI9MCZzZXhwcmVmPTEmc2VyaW91c3JlbGF0aW9uc2hpcHM9MSZyZWxpZ2lvbmlkPTAmcmVnaW9uPSZwb3N0YWxjb2RlPTkxNzY1Jm1hcml0YWxzdGF0dXM9UyZpbmNvbWVpZD00JmhlaWdodD0xNzUmZ2VuZGVyPU0mZnJpZW5kcz0xJmV0aG5pY2lkPS0xJmFnZT0yNyZib2R5dHlwZWlkPTImY2hpbGRyZW5pZD0xJmNvdW50cnk9VVMmZGF0aW5nPTEmZHJpbmtlcj0xJmVkdWNhdGlvbmlkPTM%3D; DOMAIN=myspace.com");

	web_add_cookie("MYSPACE=myspace; DOMAIN=myspace.com");

	web_add_cookie("TIMEZONE=2; DOMAIN=myspace.com");

	web_add_cookie("AUTOSONGPLAY=0; DOMAIN=myspace.com");

	web_add_cookie("FRNDID=15537523; DOMAIN=myspace.com");

	web_add_cookie("ME=laurence%5Fmaar%40hotmail%2Ecom; DOMAIN=myspace.com");

	web_url("myspace.com", 
		"URL=http://myspace.com/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t187.inf", 
		"Mode=HTTP", 
		"LAST");
 
# 34 "Login.c"
 
# 45 "Login.c"
 
# 54 "Login.c"
 
# 65 "Login.c"
 
# 116 "Login.c"
	lr_start_transaction("Login");

	web_add_cookie("MYSPACE=myspace; DOMAIN=home.myspace.com");

	web_add_cookie("AUTOSONGPLAY=0; DOMAIN=home.myspace.com");

	web_add_cookie("FRNDID=15537523; DOMAIN=home.myspace.com");

	 
    web_reg_save_param(
		"tokenID", 
       	"LB=Mytoken=",
		"RB=\">", 
		"LAST");

	web_submit_data("index.cfm", 
		"Action=http://myspace.com/index.cfm?fuseaction=login.process", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://myspace.com/", 
		"Snapshot=t193.inf", 
		"Mode=HTTP", 
		"ITEMDATA", 
		"Name=email", "Value=laurence_maar@hotmail.com", "ENDITEM", 
		"Name=password", "Value=simba", "ENDITEM", 
		"Name=Remember", "Value=Remember", "ENDITEM", 
		"Name=Submit22.x", "Value=13", "ENDITEM", 
		"Name=Submit22.y", "Value=5", "ENDITEM", 
		"LAST");
 
# 183 "Login.c"
 
# 200 "Login.c"
	lr_end_transaction("Login",2);

	lr_think_time(3);

	return 0;
}
# 6 "c:\\documents and settings\\lmaar\\desktop\\load runner\\myspace\\ms100\\\\combined_MS100.c" 2

# 1 "MSF01_Friends_Search.c" 1
MSF01_Friends_Search( char *searchFirstName )
{

	lr_save_string( searchFirstName, "searchFirstName" );

 
# 27 "MSF01_Friends_Search.c"
	lr_start_transaction("SearchLink");

	web_add_cookie("MYSPACE=myspace; DOMAIN=search.myspace.com");

	web_add_cookie("AUTOSONGPLAY=0; DOMAIN=search.myspace.com");

	web_add_cookie("FRNDID=15537523; DOMAIN=search.myspace.com");

	lr_continue_on_error (1);

	web_url("index.cfm_2", 
		"URL=http://search.myspace.com/index.cfm?fuseaction=find&Mytoken={tokenID}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://home.myspace.com/index.cfm?fuseaction=user&DERDB=ZG9tYWluPWhvdG1haWwmdGxkPWNvbSZzbW9rZXI9MCZzZXhwcmVmPTEmc2VyaW91c3JlbGF0aW9uc2hpcHM9MSZyZWxpZ2lvbmlkPTAmcmVnaW9uPSZwb3N0YWxjb2RlPTkxNzY1Jm1hcml0YWxzdGF0dXM9UyZpbmNvbWVpZD00JmhlaWdodD0xNzUmZ2VuZGVyPU0mZnJpZW5kcz0xJmV0aG5pY2lkPS0xJmFnZT0yNyZib2R5dHlwZWlkPTImY2hpbGRyZW5pZD0xJmNvdW50cnk9VVMmZGF0aW5nPTEmZHJpbmtlcj0xJmVkdWNhdGlvbmlkPTM=&setonlinenow=1", 
		"Snapshot=t200.inf", 
		"Mode=HTML", 
		"LAST");
	
	lr_continue_on_error (0);

 
# 66 "MSF01_Friends_Search.c"
 
# 83 "MSF01_Friends_Search.c"
 
# 112 "MSF01_Friends_Search.c"
	lr_end_transaction("SearchLink",2);

	lr_think_time(3);

	lr_start_transaction("Search");

	web_add_cookie("MYSPACE=myspace; DOMAIN=www.myspace.com");

	web_add_cookie("AUTOSONGPLAY=0; DOMAIN=www.myspace.com");

	web_add_cookie("FRNDID=15537523; DOMAIN=www.myspace.com");

	 
    web_reg_save_param(
		"friendID", 
       	"LB=.viewprofile&friendID=",
		"RB=&Mytoken=", 
		"ORD=ALL",
		"LAST");

	 
    web_reg_save_param(
		"friendPages", 
       	"LB=<td>1-10 of ",
		"RB=</td>", 
		"ORD=1",
		"LAST");

	 



	web_url("index.cfm_3", 
		"URL=http://www.myspace.com/index.cfm?fuseaction=find&Mytoken={tokenID}&circuitaction=search&searchType=network&f_first_name={searchFirstName}&InterestType=&f_search_criteria=&noDetail=0&first=No&Major=&Clubs=&CurrentCourses=&noDetail=0&Country=&distance=-1&Postal=91765&Photos=1&Gender=2&AgeFrom=18&AgeTo=35&Page=0", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://search.myspace.com/index.cfm?fuseaction=find&Mytoken={tokenID}", 
		"Snapshot=t204.inf", 
		"Mode=HTML", 
		"LAST");
 
# 164 "MSF01_Friends_Search.c"
	lr_message( lr_eval_string( "{friendID_count}" ) );

	x = atoi( lr_eval_string( "{friendID_count}" ) );

	for( c=1; c<x+1; c++ )
	{
		sprintf( tmpString, "%d", c );
		lr_save_string( tmpString, "c" );
		lr_save_string( lr_eval_string( lr_eval_string( "{friendID_{c}}" ) ), "friendIDstring" );

		sprintf( tmpString, "%s", lr_eval_string( "{friendIDstring}" ) );

		lr_message( tmpString );

		 
# 188 "MSF01_Friends_Search.c"

		sprintf( lastString, "%s", tmpString );
	}

	lr_message( lr_eval_string( "{friendPages}" ) );

	sprintf( tmpString, "%lu", friendCounter );

	lr_message( tmpString );

 
# 209 "MSF01_Friends_Search.c"

 
# 222 "MSF01_Friends_Search.c"
 
# 255 "MSF01_Friends_Search.c"
	lr_end_transaction("Search",2);

	lr_think_time(3);


	sprintf( tmpString, "%s", lr_eval_string( "{friendPages}" ) );

	lr_message( tmpString );

	MSF05_Friends_Search_Loop( tmpString );

	return 0;
}
# 7 "c:\\documents and settings\\lmaar\\desktop\\load runner\\myspace\\ms100\\\\combined_MS100.c" 2

# 1 "MSF10_Friends_Add.c" 1
MSF10_Friends_Add( char *myFriendID )
{
	lr_start_transaction("ViewProfile");

	web_add_cookie("MYSPACE=myspace; DOMAIN=profile.myspace.com");

	web_add_cookie("AUTOSONGPLAY=0; DOMAIN=profile.myspace.com");

	web_add_cookie("FRNDID=15537523; DOMAIN=profile.myspace.com");

	lr_save_string( myFriendID, "myFriendID" );

	lr_message( "Debug Point" );

	 
# 26 "MSF10_Friends_Add.c"
 
# 37 "MSF10_Friends_Add.c"
 
# 58 "MSF10_Friends_Add.c"
 
# 71 "MSF10_Friends_Add.c"
	lr_end_transaction("ViewProfile",2);

	lr_think_time(3);

	lr_start_transaction("Addtofriends");

	 

	 
    web_reg_save_param(
		"hashcode", 
       	"LB=<input type=\"hidden\" name=\"hashcode\" value=\"",
		"RB=\">", 
		"ORD=1",
		"LAST");

	lr_continue_on_error (1);
	
	web_url("index.cfm_5", 
		"URL=http://www.myspace.com/index.cfm?fuseaction=invite.addfriend_check&friendID={myFriendID}&Mytoken={tokenID}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://profile.myspace.com/index.cfm?fuseaction=user.viewprofile&friendID={myFriendID}&Mytoken={tokenID}", 
		"Snapshot=t214.inf", 
		"Mode=HTML", 
		"LAST");

	lr_continue_on_error (0);

	lr_end_transaction("Addtofriends",2);

	lr_think_time(3);

   	lr_message( "Debug Point" );

	lr_continue_on_error (1);

	if( 1 == web_find("web_find",
		"What=You already have a pending friend request for this person",
		"LAST") )
	{
	
    	lr_start_transaction("ConfirmAdd");

    	lr_message( lr_eval_string( "{myFriendID}" ) );
    	lr_message( lr_eval_string( "{hashcode}" ) );

    	lr_message( "Debug Point" );

    	web_add_cookie("MYSPACE=myspace; DOMAIN=invite.myspace.com");

    	web_add_cookie("AUTOSONGPLAY=0; DOMAIN=invite.myspace.com");

    	web_add_cookie("FRNDID=15537523; DOMAIN=invite.myspace.com");

    	web_submit_data("index.cfm_6", 
    		"Action=http://www.myspace.com/index.cfm?fuseaction=invite.addFriendsUpdate&Mytoken={tokenID}", 
    		"Method=POST", 
    		"TargetFrame=", 
    		"RecContentType=text/html", 
    		"Referer=http://www.myspace.com/index.cfm?fuseaction=invite.addfriend_check&friendID={myFriendID}&Mytoken={tokenID}", 
    		"Snapshot=t217.inf", 
    		"Mode=HTML", 
    		"ITEMDATA", 
    		"Name=hashcode", "Value={hashcode}", "ENDITEM", 
    		"Name=friendID", "Value={myFriendID}", "ENDITEM", 
    		"LAST");

    	lr_end_transaction("ConfirmAdd",2);

    	lr_think_time(3);

		noAdd++;
	}
	else
	{
		noAlready++;
	}

	lr_continue_on_error (0);

	return 0;
}
# 8 "c:\\documents and settings\\lmaar\\desktop\\load runner\\myspace\\ms100\\\\combined_MS100.c" 2

# 1 "vuser_end.c" 1
vuser_end()
{
	sprintf( tmpString, "***!~ Stats: %d pages, %d friends, %d adds, %d already added", noPages, noFriends, noAdd, noAlready );
	lr_message( tmpString );

	return 0;
}
# 9 "c:\\documents and settings\\lmaar\\desktop\\load runner\\myspace\\ms100\\\\combined_MS100.c" 2

