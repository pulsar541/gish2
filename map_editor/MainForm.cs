/*
 * Created by SharpDevelop.
 * User: pulsar
 * Date: 14.07.2007
 * Time: 17:35
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */

using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
using System.IO;

namespace redaktor
{
	/// <summary>
	/// Description of MainForm.
	/// </summary>
	
		
	
	public partial class MainForm
	{
		[STAThread]
		public static void Main(string[] args)
		{
			Application.EnableVisualStyles();
			Application.SetCompatibleTextRenderingDefault(false);
			Application.Run(new MainForm());
		}
		
		public MainForm()
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
		
		struct Thing
		{
			public char ind;
			public int x0,y0,x1,y1;
		}
		
		public struct Tool
		{
				public char type;
				public Image img;
				public Rectangle rect;
				public int maxCount;
				public Tool(char type,string imageFile,int maxCount, int x,int y,int  w,int  h) 
				{
					this.type = type;
					this.img = new Bitmap(imageFile);
					this.rect = new Rectangle(x,y,w,h);
					this.maxCount = maxCount;
				}
		}
		
		List<Tool> tools = new List<Tool>();
		
		Thing[,] th = new Thing[100,100];
		int size = 10;
		
		void MainFormPaint(object sender, System.Windows.Forms.PaintEventArgs e)
		{ 
			Graphics dc = e.Graphics;	
			

			
			for(int i=0;i<100;i++)
			{
				//dc.DrawLine(Pens.LightGray,0,i*size + 50,this.Width,i*size+ 50);
				//dc.DrawLine(Pens.LightGray,i*size,50,i*size,this.Height);
				
				for(int j=0;j<100;j++)
				{			
					foreach (Tool tool in tools)
					{
						
						if(th[i,j].ind == tool.type)
							 dc.DrawImage(tool.img,new Rectangle(th[i,j].x0,th[i,j].y0,size,size));
		
					}	
					
					if(!RB && ex>th[i,j].x0 && ex<=th[i,j].x1
						   && ey>th[i,j].y0 && ey<=th[i,j].y1)	
					{	
						foreach (Tool tool in tools)
						{
							if(type == tool.type)
								 dc.DrawImage(tool.img,new Rectangle(th[i,j].x0,th[i,j].y0,size,size));
			
						}	
						
					}
				}
			}	
				
			foreach (Tool tool in tools)
					{
							dc.DrawImage(tool.img, tool.rect);
					}	
		
			
		/*	dc.FillEllipse(Brushes.Yellow,ex+10,ey+10,40,40);
			dc.DrawEllipse(Pens.Black,ex+10,ey+10,40,40);			
			switch (type)
			{
					case 1: dc.DrawImage(img,new Rectangle(ex+20,ey+20,20,20));
					break;
					
			}*/
		}
		
		void Panel1Paint(object sender, System.Windows.Forms.PaintEventArgs e)
		{
			
		}
	}
}
