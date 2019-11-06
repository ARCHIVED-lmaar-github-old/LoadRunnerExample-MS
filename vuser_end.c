vuser_end()
{
	sprintf( tmpString, "***!~ Stats: %d pages, %d friends, %d adds, %d already added", noPages, noFriends, noAdd, noAlready );
	lr_message( tmpString );

	return 0;
}
