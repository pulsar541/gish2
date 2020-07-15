#include "font.h"

void CFont::CreateOpenGLFont(LPSTR strFontName, int height)	// Build Our Bitmap Font
{
	g_FontListID=0;
	UINT	fontListID = 0;								// This will hold the base ID for our display list
	HFONT	hFont;										// This will store the handle to our font

	font_height=height;

	fontListID = glGenLists(MAX_CHARS);					// Generate the list for the font

	hFont = CreateFont(	height,							// Our desired HEIGHT of the font
						0,								// The WIDTH (If we leave this zero it will pick the best width depending on the height)
						GM_COMPATIBLE,								// The angle of escapement
						0,								// The angle of orientation
						FW_NORMAL,								// The font's weight (We want it bold)
						FALSE,							// Italic - We don't want italic
						FALSE,							// Underline - We don't want it underlined
						FALSE,							// Strikeout - We don't want it strikethrough
						DEFAULT_CHARSET,					// This is the type of character set
						OUT_CHARACTER_PRECIS,					// The Output Precision
						CLIP_DEFAULT_PRECIS,			// The Clipping Precision
						DEFAULT_QUALITY,			// The quality of the font - We want anitaliased fonts
						DEFAULT_PITCH,				// The family and pitch of the font.  We don't care.
						strFontName);					// The font name (Like "Arial", "Courier", etc...)

	h_DC = GetDC(NULL);
	hOldFont = (HFONT)SelectObject(h_DC, hFont);

	wglUseFontBitmaps(h_DC, 0, MAX_CHARS - 1, fontListID);


	//ReleaseDC(hwnd, hDC);
	g_FontListID=fontListID;
	return;									
}

void CFont::PositionText( int x, int y, int win_height )
{

	glPushAttrib( GL_TRANSFORM_BIT | GL_VIEWPORT_BIT );

	// Here we use a new projection and modelview matrix to work with.
	glMatrixMode( GL_PROJECTION );						// Set our matrix to our projection matrix
	glPushMatrix();										// Push on a new matrix to work with
	glLoadIdentity();	// reset the matrix
	static float winw=(float)((4.0*(float)win_height)/3.0);

	gluOrtho2D(0,winw,0,win_height);
	glMatrixMode( GL_MODELVIEW );						// Set our matrix to our model view matrix
	glPushMatrix();										// Push on a new matrix to work with
	glLoadIdentity();									// Reset that matrix

	y = win_height - font_height - y;				// Calculate the weird screen position

//	glViewport( x - 1, y - 1, 0, 0 );					// Create a new viewport to draw into

	glRasterPos2f( x, y);						// Set the drawing position

	glPopMatrix();										// Pop the current modelview matrix off the stack
	glMatrixMode( GL_PROJECTION );						// Go back into projection mode
	glPopMatrix();										// Pop the projection matrix off the stack

	glPopAttrib();										// This restores our TRANSFORM and VIEWPORT attributes
}


void CFont::glDrawText(int win_height, int x, int y, const char *strString, ...)
{	
	char		strText[256];							// This will hold our text to display
	va_list		argumentPtr;							// This will hold the pointer to the argument list

	if (strString == NULL)								// Check if a string was given
		return;											// Don't render anything then

	va_start(argumentPtr, strString);					// Parse the arguments out of the string
	vsprintf(strText, strString, argumentPtr);			// Now add the arguments into the full string

	va_end(argumentPtr);								// This resets and frees the pointer to the argument list.

	PositionText(x, y, win_height);						// Call our own function to position the text on screen
	glPushAttrib(GL_LIST_BIT);							// This saves the list base information	
	glListBase(g_FontListID);							// This sets the lists base
	glCallLists(strlen(strText), GL_UNSIGNED_BYTE, strText);
	glPopAttrib();										// Return the display list back to it's previous state
	
}

void CFont::DestroyFont()										
{
	glDeleteLists(g_FontListID, MAX_CHARS);				// Free the display list
	SelectObject(h_DC, hOldFont);						// Select the old font back in so we don't have memory leaks
}


void CFont::ShowLabelText(int x, int y, char * OutString, int r, int g, int b)
{
    int		length=0;
	HDC		hdc=NULL;
	HFONT	smallfont;

	hdc = GetDC(NULL);
	smallfont = CreateFont(font_height,
                         0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
                         ANSI_CHARSET,
                         OUT_DEFAULT_PRECIS,
                         CLIP_DEFAULT_PRECIS,
                         DEFAULT_QUALITY,
                         VARIABLE_PITCH,
                         "Arial");
	
	SelectObject(hdc, smallfont);
	SetTextColor(hdc, RGB(r, g, b));

	TextOut(hdc, x, y, OutString, strlen(OutString));

	ReleaseDC(h_Wnd, hdc);
	OutString=0;
}

void CFont::ShowLabelInt(int x, int y, int mes, int r, int g, int b)
{
	HDC		hdc=NULL;
	HFONT	smallfont;

	char buff[128] = {0};

	hdc = GetDC(NULL);
	smallfont = CreateFont(font_height,
                         0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
                         ANSI_CHARSET,
                         OUT_DEFAULT_PRECIS,
                         CLIP_DEFAULT_PRECIS,
                         DEFAULT_QUALITY,
                         VARIABLE_PITCH,
                         "Arial");
	
	SelectObject(hdc, smallfont);
	SetTextColor(hdc, RGB(r, g, b));
	
	sprintf(buff, "%d", mes);
	TextOut(hdc, x, y, buff, strlen(buff));

	ReleaseDC(h_Wnd, hdc);
}
