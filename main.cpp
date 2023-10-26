#include <gtk/gtk.h>

void welcome(GtkButton *button, gpointer data);

int main(int argc, char *argv[])
{
  GtkWidget *window;
  GtkWidget *button;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  button = gtk_button_new_with_label("Hello, lil sunny!");
  gtk_container_add(GTK_CONTAINER(window), button);

  gtk_window_set_title(GTK_WINDOW(window), "My first program");
  gtk_container_set_border_width(GTK_CONTAINER(window), 50);

  g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(welcome), NULL);
  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}

void welcome(GtkButton *button, gpointer data)
{
  GtkWidget *label;
  GtkWidget *dialog;
  GtkWidget *content_area;

  dialog = gtk_dialog_new_with_buttons("Dialog", NULL, GTK_DIALOG_DESTROY_WITH_PARENT, "_OK", GTK_RESPONSE_ACCEPT, NULL);

  content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

  label = gtk_label_new("Hello baby!");

  gtk_container_add(GTK_CONTAINER(content_area), label);
  gtk_widget_show(label);

  gtk_dialog_run(GTK_DIALOG(dialog));
  gtk_widget_destroy(dialog);
}