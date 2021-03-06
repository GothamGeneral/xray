//-
// ==========================================================================
// Copyright (C) 1995 - 2006 Autodesk, Inc. and/or its licensors.  All 
// rights reserved.
//
// The coded instructions, statements, computer programs, and/or related 
// material (collectively the "Data") in these files contain unpublished 
// information proprietary to Autodesk, Inc. ("Autodesk") and/or its 
// licensors, which is protected by U.S. and Canadian federal copyright 
// law and by international treaties.
//
// The Data is provided for use exclusively by You. You have the right 
// to use, modify, and incorporate this Data into other products for 
// purposes authorized by the Autodesk software license agreement, 
// without fee.
//
// The copyright notices in the Software and this entire statement, 
// including the above license grant, this restriction and the 
// following disclaimer, must be included in all copies of the 
// Software, in whole or in part, and all derivative works of 
// the Software, unless such copies or derivative works are solely 
// in the form of machine-executable object code generated by a 
// source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND. 
// AUTODESK DOES NOT MAKE AND HEREBY DISCLAIMS ANY EXPRESS OR IMPLIED 
// WARRANTIES INCLUDING, BUT NOT LIMITED TO, THE WARRANTIES OF 
// NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR 
// PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE, OR 
// TRADE PRACTICE. IN NO EVENT WILL AUTODESK AND/OR ITS LICENSORS 
// BE LIABLE FOR ANY LOST REVENUES, DATA, OR PROFITS, OR SPECIAL, 
// DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES, EVEN IF AUTODESK 
// AND/OR ITS LICENSORS HAS BEEN ADVISED OF THE POSSIBILITY 
// OR PROBABILITY OF SUCH DAMAGES.
//
// ==========================================================================
//+

//
// Define declarations
//

#define kRockingTransformNodeID 0x8101B
#define kRockingTransformMatrixID 0x8101C

#define ReturnOnError(status)			   \
		if (MS::kSuccess != status) {	   \
			return status;				  \
		}

//
// Class declarations -- matrix and transform
//

class rockingTransformMatrix : public MPxTransformationMatrix
{
	// A really simple implementation of MPxTransformationMatrix.
	// The methods include:
	// - Two accessor methods for getting and setting the 
	// rock
	// - The virtual asMatrix() method which passes the matrix 
	// back to Maya when the command "xform -q -ws -m" is invoked

	public:
		rockingTransformMatrix();
		static void *creator();
		
		virtual MMatrix asMatrix() const;
		virtual MMatrix	asMatrix(double percent) const;
		virtual MMatrix	asRotateMatrix() const;
		
		// Degrees
		double	getRockInX() const;
		void	setRockInX( double rock );
		
		static	MTypeId	id;
	protected:		
		typedef MPxTransformationMatrix ParentClass;
		// Degrees
		double rockXValue;
};

class rockingTransformNode : public MPxTransform 
{
	// A really simple custom transform.
	public:
		rockingTransformNode();
		rockingTransformNode(MPxTransformationMatrix *);
		virtual ~rockingTransformNode();

		virtual MPxTransformationMatrix *createTransformationMatrix();
					
		virtual void postConstructor();

		virtual MStatus validateAndSetValue(const MPlug& plug,
					const MDataHandle& handle, const MDGContext& context);
					
		virtual void  resetTransformation (MPxTransformationMatrix *);
		virtual void  resetTransformation (const MMatrix &);
					
		// Utility for getting the related rock matrix pointer
		rockingTransformMatrix *getRockingTransformMatrix();
				
		const char* className();
		static	void * 	creator();
		static  MStatus	initialize();
		
		static	MTypeId	id;
	protected:
		// Degrees
		static	MObject aRockInX;
		double rockXValue;
		typedef MPxTransform ParentClass;
};

class DegreeRadianConverter
{
	public:
		double degreesToRadians( double degrees );
		double radiansToDegrees( double radians );
};
