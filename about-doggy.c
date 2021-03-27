#include <gtk/gtk.h>

// The function of the button
// When the button was clicked, the program will be killed.
void deal_pressed(GtkButton *button, gpointer user_data)
{
  const char *text = gtk_button_get_label(button); // Get the label of the button.
  printf("%s\n ========= \n%s\n", (char *)user_data, text); // Print 
  gtk_main_quit(); // End.
}

int main(int argc, char *argv[])
{
  gtk_init(&argc, &argv); //initial
  GtkWidget *box = gtk_vbox_new(FALSE, 10);

  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL); // Create the topest window.
  // Create a button, the label is "Hello World, GTK+."
  GtkWidget *button = gtk_button_new_with_label("确定");
  // Create a label.
  GtkWidget *label = gtk_label_new("贡献者名单\n\n编程\nWeepingDogel 桃桃（辅）\n\n测试\n桃桃\n\n翻译\nMika 齐樱酱\n\n壁纸绘制\n狐狐");
	// The window is unable to resize.
  gtk_window_set_resizable(window, FALSE);
  // set the size of the window
  gtk_widget_set_size_request(window, 300, 339);
  // Set the title.
  gtk_window_set_title(window, "关于 Doggy");
  // set the position of the window.
  // GTK_WIN_POS_MOUSE:  apear close to the mouse.
  gtk_window_set_position(window, GTK_WIN_POS_MOUSE);
  // set the border width of the window, 15px.
	gtk_container_set_border_width(GTK_CONTAINER(window), 15);
  // Put the button into the box.
  // And put the box into the window.
  // The window is a kind of container.
  gtk_container_add(GTK_CONTAINER(window), box);
  gtk_container_add(GTK_CONTAINER(box), label);
  gtk_container_add(GTK_CONTAINER(box), button);
  // Now, it's time to display everything.
  // gtk_widget_show() is a function which is used to display an object.
  // A name of a control is needed to provide.
  g_signal_connect(button, "clicked", G_CALLBACK(deal_pressed), "The first GTK program made by weepingdogel.");
  gtk_widget_show_all(window); // display the window.
  // destroy the window.
  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  gtk_main(); // launch all the things.

  return 0;
}