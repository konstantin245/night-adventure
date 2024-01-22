  
   namespace ГШГШЗЕ9ШЗЕПГШЖПЭПГШ
{
    public partial class Form1 : Form
    {

        Button btn1 = new Button();
        PictureBox[] picter = new PictureBox[4];
            int n = 0;
        public Form1()
        {
            InitializeComponent();
        }
        private void btn1_Click(object sender, EventArgs e)
        {
            picter[0] = new PictureBox();
            picter[0].Image = Image.FromFile("1.jpg");
            picter[0].Location = new Point(400, 300);
            picter[0].Size = new System.Drawing.Size(300, 300);
            this.Controls.Add(picter[0]);

        }
        private void Form1_Load(object sender, EventArgs e)
        {
            Button btn1 = new Button();
            btn1.Name = "Hello world";
            btn1.Text = "New button";
            btn1.Size = new System.Drawing.Size(100, 40);   
            btn1.Location = new Point(100, 100);
            this.Controls.Add(btn1);

            btn1.Click += new EventHandler(btn1_Click);

            this.Controls.Add(btn1 );
        }
    }
}
