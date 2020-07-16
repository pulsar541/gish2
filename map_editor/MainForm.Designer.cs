/*
 * Created by SharpDevelop.
 * User: pulsar
 * Date: 14.07.2007
 * Time: 17:35
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
namespace redaktor
{
	partial class MainForm : System.Windows.Forms.Form
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		
		/// <summary>
		/// Disposes resources used by the form.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing) {
				if (components != null) {
					components.Dispose();
				}
			}
			base.Dispose(disposing);
		}
		
		/// <summary>
		/// This method is required for Windows Forms designer support.
		/// Do not change the method contents inside the source code editor. The Forms designer might
		/// not be able to load this method if it was changed manually.
		/// </summary>
		private void InitializeComponent()
		{
			this.button1 = new System.Windows.Forms.Button();
			this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
			this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
			this.button2 = new System.Windows.Forms.Button();
			this.button3 = new System.Windows.Forms.Button();
			this.label1 = new System.Windows.Forms.Label();
			this.SuspendLayout();
			// 
			// button1
			// 
			this.button1.BackColor = System.Drawing.Color.Gainsboro;
			this.button1.Location = new System.Drawing.Point(0, 30);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(104, 23);
			this.button1.TabIndex = 0;
			this.button1.Text = "Сохранить как...";
			this.button1.UseVisualStyleBackColor = false;
			this.button1.Click += new System.EventHandler(this.Button1Click);
			// 
			// saveFileDialog1
			// 
			this.saveFileDialog1.FileOk += new System.ComponentModel.CancelEventHandler(this.SaveFileDialog1FileOk);
			// 
			// openFileDialog1
			// 
			this.openFileDialog1.FileName = "openFileDialog1";
			this.openFileDialog1.FileOk += new System.ComponentModel.CancelEventHandler(this.OpenFileDialog1FileOk);
			// 
			// button2
			// 
			this.button2.BackColor = System.Drawing.Color.Gainsboro;
			this.button2.Location = new System.Drawing.Point(0, 1);
			this.button2.Name = "button2";
			this.button2.Size = new System.Drawing.Size(104, 23);
			this.button2.TabIndex = 0;
			this.button2.Text = "Открыть";
			this.button2.UseVisualStyleBackColor = false;
			this.button2.Click += new System.EventHandler(this.Button2Click);
			this.button2.ClientSizeChanged += new System.EventHandler(this.Button2ClientSizeChanged);
			// 
			// button3
			// 
			this.button3.BackColor = System.Drawing.Color.Gainsboro;
			this.button3.Location = new System.Drawing.Point(110, 1);
			this.button3.Name = "button3";
			this.button3.Size = new System.Drawing.Size(75, 23);
			this.button3.TabIndex = 1;
			this.button3.Text = "Новый";
			this.button3.UseVisualStyleBackColor = false;
			this.button3.Click += new System.EventHandler(this.Button3Click);
			// 
			// label1
			// 
			this.label1.Location = new System.Drawing.Point(0, 0);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(100, 23);
			this.label1.TabIndex = 0;
			this.label1.Text = "label1";
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.BackColor = System.Drawing.Color.White;
			this.ClientSize = new System.Drawing.Size(967, 766);
			this.Controls.Add(this.button3);
			this.Controls.Add(this.button2);
			this.Controls.Add(this.button1);
			this.Name = "MainForm";
			this.Text = "redaktor.  Useinov Evgeni";
			this.Paint += new System.Windows.Forms.PaintEventHandler(this.MainFormPaint);
			this.MouseUp += new System.Windows.Forms.MouseEventHandler(this.MainFormMouseUp);
			this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.MainFormMouseMove);
			this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.MainFormMouseDown);
			this.Load += new System.EventHandler(this.MainFormLoad);
			this.ResumeLayout(false);
		}
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Button button3;
		private System.Windows.Forms.Button button2;
		private System.Windows.Forms.OpenFileDialog openFileDialog1;
		private System.Windows.Forms.SaveFileDialog saveFileDialog1;
		private System.Windows.Forms.Button button1;

		
		void MainFormLoad(object sender, System.EventArgs e)
		{
			int toolPosX0 = 180;
		
			System.IO.StreamReader sr = new System.IO.StreamReader("tools.dat");
			while(!sr.EndOfStream)
			{
			 string[] toolParams = sr.ReadLine().Split(':');
			 tools.Add( new Tool(
			                     toolParams[0].Trim()[0],
			                     toolParams[1].Trim(),
			                     int.Parse(toolParams[2].Trim()),
			                     toolPosX0+=30, 10,30,30));
			}
			sr.Close();
	
					for (int i=0; i<100;i++)
				for(int j=0;j<100;j++)
				{th[i,j].ind = '0';
				 th[i,j].x0 = i * size;
				 th[i,j].y0 = j * size + 50;
				 th[i,j].x1 = th[i,j].x0 + size; 
				 th[i,j].y1 = th[i,j].y0 + size;			 
				}
				
				this.DoubleBuffered = true;
		}
		bool LB = false;
		bool RB = false;
		char  type = '0';
		int ex,ey;
		
		
		void MainFormMouseDown(object sender, System.Windows.Forms.MouseEventArgs e)
		{ 
			if (e.Button.ToString() == "Left") LB = true;
			if (e.Button.ToString() == "Right") RB = true;	
		
			SetPixel(e.X,e.Y);
			
			ex = e.X;
			ey = e.Y;
			
			foreach (Tool tool in tools)
			{
				if(tool.rect.Contains(e.X,e.Y))	type = tool.type;
			}
			
				
		}
		
		void Button1Click(object sender, System.EventArgs e)
		{
			saveFileDialog1.ShowDialog();
		}
		
		
		void SaveFileDialog1FileOk(object sender, System.ComponentModel.CancelEventArgs e)
		{
			System.IO.StreamWriter sw = new System.IO.StreamWriter(saveFileDialog1.FileName);
			
			for (int j=0; j<100;j++)
			{		for(int i=0;i<100;i++)
					{	sw.Write(th[i,j].ind);						
					} 
				sw.WriteLine();
			}
			sw.Close();	
		}
		
		void Button2ClientSizeChanged(object sender, System.EventArgs e)
		{
			
		}
		
		void Button2Click(object sender, System.EventArgs e)
		{
			openFileDialog1.ShowDialog();
		}
		
		void OpenFileDialog1FileOk(object sender, System.ComponentModel.CancelEventArgs e)
		{
			System.IO.StreamReader sr = new System.IO.StreamReader(openFileDialog1.FileName);
			for (int j=0; j<100;j++)
			{	
				for(int i=0;i<100;i++)
				{
					th[i,j].ind = (char)sr.Read();
				}
				sr.Read();					
				sr.Read();
			}
			
			sr.Close();
			Invalidate();
		}
	
		void SetPixel(int ex,int ey)
		{	
			int i  = ex/System.Math.Abs(th[0,0].x0 - th[0,0].x1);
			int j  = ey/System.Math.Abs(th[0,0].y0 - th[0,0].y1)-5;	
			
			if(i>=0 && i<100 && j>=0 && j<100 )
			{
				if (LB) th[i,j].ind = type;
				if (RB) th[i,j].ind = '0';								
			}
			Invalidate();
		}
		
		void MainFormMouseMove(object sender, System.Windows.Forms.MouseEventArgs e)
		{
			SetPixel(e.X,e.Y);
			ex = e.X;
			ey = e.Y;
		}
		
		void MainFormMouseUp(object sender, System.Windows.Forms.MouseEventArgs e)
		{
			if (e.Button.ToString() == "Left") LB = false;
			if (e.Button.ToString() == "Right") RB = false;	
		}
		
		void Button3Click(object sender, System.EventArgs e)
		{
			for (int i=0; i<100;i++)
				for(int j=0;j<100;j++)
				th[i,j].ind = '0';
			Invalidate();
		}
	}
}
