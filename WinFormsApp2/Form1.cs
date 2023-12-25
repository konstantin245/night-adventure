namespace WinFormsApp2
{
    public partial class Form1 : Form
    {
        double x = 0;
        string y;
        double x1 = 0;
        string y1;
        double sum; //сумма
        double mul; //умножить
        double sub; //вычитание
        double div; //деление
        double squ =0; //корень
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //button1.Text = "Danisik)";
            label1.Text = "";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            x1 = x1 + 1;
            y1 = x1.ToString();
            button1.Text = y1;

        }

        private void button2_Click(object sender, EventArgs e)
        {
            x = x + 1;
            y = x.ToString();
            button2.Text = y;

        }

        private void button3_Click(object sender, EventArgs e)
        {
            sum = x + x1;
            label1.Text = sum.ToString();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            mul = x * x1;
            label1.Text = mul.ToString();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            sub = x1 - x;
            label1.Text = sub.ToString();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            div = x1 / x;
            label1.Text = div.ToString();
        }

        private void button9_Click(object sender, EventArgs e)
        {
            x1 = 0;
            x = 0;
            y1 = x1.ToString();
            button1.Text = y1;
            y = x.ToString();
            button2.Text = y;
            label1.Text = "";
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            string slovo= textBox1.Text; //число с 1 поисковой строки
            if (slovo!=null) x1 = Int32.Parse(slovo);
            button1.Text = slovo;
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            string slovo1 = textBox2.Text; //число с 2 поисковой строки
            if (slovo1 != null) x = Int32.Parse(slovo1);
            button2.Text = slovo1;
        }

        private void button10_Click(object sender, EventArgs e)
        {
            string y;
            double sumSq= Math.Sqrt(x+x1);
            y = sumSq.ToString();
            label1.Text = y;
        }
    }
}