using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing;
using System.IO;

namespace MapEditor
{
    public class Map_Info
    {
        static public int imgSelect;
        //Xác lập chiều dài và rộng đối tượng trên Map
        static public int Item_Height = 40;
        static public int Item_Width = 40;
        //Thiết lập màu
        static public Color Grid_Color = Color.White;
        static public Color Background = Color.FromArgb(65, 128, 190);
        //Số lượng phần tử trong ma trận Matrix[y,x]
        static public int Width;
        static public int Height;
        //Phần tử mặc định ban đầu của map
        static public int Default = 0;
        //Danh sách các đối tượng được vẽ.
        static public List<string> list_Object = new List<string>();
        
        private string[,] Matrix;
       

        public string[,] _Matrix
        {
            get { return Matrix; }
            set { Matrix = value; }
        }

        //Khởi tạo giá trị mặc định cho ma trận
        public void Clear()
        {
            Matrix = new string[Width, Height];
            for (int i = 0; i < Width; i++)
                for (int j = 0; j < Height; j++)
                    Matrix[i, j] = null;
        }

        //Mở rộng Map
        public void Add(int cols, int rows)
        { 
            string[,] Temp;
            Temp = Matrix;
            Matrix = new string[Width + cols, Height + rows];

            //gán tất cả giá trị là 0
            for (int i = 0; i < Width + cols; i++)
                for (int j = 0; j < Height + rows; j++)
                {
                    Matrix[i, j] = null;
                }
            //danh dau cac vi tri ve
            for (int i = 0; i < Width; i++)
                for (int j = 0; j < Height; j++)
                {
                    Matrix[i, j] = Temp[i, j];
                }

            Temp = null;
            Width += cols;
            Height += rows;
        }

        //di chuyen sang trai
        public bool MoveLeft(int valueMove = 10)
        {
            List<string> list_temp = new List<string>();
            list_temp.Add(list_Object[0]);
            list_temp.Add(list_Object[1]);

            foreach( string Object in list_Object )
            {
                string[] info_Obj = Object.Split(' ');

                if (list_Object.IndexOf(Object) > 1)
                {
                    if ((Int32.Parse(info_Obj[1]) - valueMove) >= 0)
                    {
                        info_Obj[1] = (Int32.Parse(info_Obj[1]) - valueMove).ToString();
                        list_temp.Add(String.Join(" ", info_Obj));
                    }
                    else
                    {
                        MessageBox.Show("Can't Move");
                        return false;
                    }
                }
                
            }

            list_Object = list_temp;
            return true;
           
        }

        //Thay đổi giá trị một phần tử của ma trận
        public void Change(Point pt, string str)
        {
            
            Matrix[pt.X, pt.Y] = str;

            if (pt.X > Int32.Parse(list_Object[0]) ) list_Object[0]= (pt.X + Item_Width).ToString();
            if (pt.Y > Int32.Parse(list_Object[1]) ) list_Object[1] = (pt.Y + Item_Height).ToString();

            list_Object.Add(str+" "+pt.X.ToString()+" "+pt.Y.ToString());
        }

        //Đọc Map
        public void Open(string filename)
        {
            try
            {
                if (list_Object.Count > 0) list_Object.Clear();
                StreamReader sr = new StreamReader(filename);
                string str = sr.ReadLine();

                while (str != null)
                {
                    list_Object.Add(str);
                    str = sr.ReadLine();
                }

                sr.Close();
                sr.Dispose();

                try
                {
                    Width = Int32.Parse(list_Object[0].ToString());
                    Height = Int32.Parse(list_Object[1].ToString());
                    Matrix = new string[Width, Height];
                }
                catch (Exception)
                {
                    MessageBox.Show("This is not file Map");
                    return;
                }

                
                string[] valueObject;
                foreach (string info_Object in list_Object)
                {
                    valueObject = info_Object.Split(' ');

                    try
                    {
                        if (list_Object.IndexOf(info_Object) > 1)
                            Matrix[Int32.Parse(valueObject[1]), Int32.Parse(valueObject[2])] = valueObject[0];
                    }
                    catch { }
                }
            }
            catch
            {
                
            }

        }

        //Lưu Map
        public void Save()
        {
            try
            {
                SaveFileDialog saveFileDlg = new SaveFileDialog();
                saveFileDlg.InitialDirectory = Application.ExecutablePath;
                saveFileDlg.Filter = "all file (*.txt)|*.txt";
                if (saveFileDlg.ShowDialog() == DialogResult.OK)
                {
                    FileStream fs = new FileStream(saveFileDlg.FileName, FileMode.Create);
                    StreamWriter sw = new StreamWriter(fs);

                    foreach (string info_Object in list_Object)
                    {
                        sw.WriteLine(info_Object);
                    }

                    sw.Flush();
                    sw.Close();
                    fs.Close();
                }
            }
            catch{}
        }
    }
}

