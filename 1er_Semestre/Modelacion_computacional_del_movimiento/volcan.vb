Option Explicit
'   Some notes on this Projectile program.
'
'   To eliminate fluid drag - just set the fluid kinematic viscosity = 0.0
'
'   Some handy property values:
'
'      Fluids:
'         Density of Air at 70F (= 21C, = 294K) = 1.19 kg/m^3
'         Kinematic Viscosity (=Dynamic Viscosity/Density) of Air at 70F
'                              = .00001536 m^2/s
'         Density of Water at 70F = 998 kg/m^3
'         Kinematic Viscosity of Water = .000000985 m^2/s
'
'      Densities of Some possible projectile materials (all in kg/m^3):
'         Stainless Steel           8055
'         Carbon Steel              7854
'         Lead                     11340
'         Aluminum Alloy            2702
'         Concrete                  2300
'         Wood (Oak)                 545
'         Rock (Granite)            2630
'         Hard Vulcanized Rubber    1190
'         Helium (just the gas)         .166

'   Definitions of some intermediate variables:
'   Rhobar = [density of fluid] / [density of projectile]
'            (For most projectiles in air, this value will be small.)
'   Amass  = 1.0 + rhobar
'            (This will be close to one usually. It includes the 'apparent' mass of
'             the fluid that has to be accelerated -- which is usually negligible.)
'   Bgrav  = (1.0 - rhobar)*g
'            (This includes both weight and buoyancy, with the latter usually
'             not very important.)
'   CCoef  = .75*rhobar/diameter of projectile
'            (This is the coefficient appearing in drag term.)
'***********************************************************************************

Sub KUTTA()
' ****************************************************************************
'   Fourth-order Runge-Kutta formulae for solving two simultaneous,
'   second-order ordinary differential equations written as:
'     DX/DT=U , DU/DT=FXoverM(U,V,UFluid, etc.) ,
'     DY/DT=V , DV/DT=FYoverM(U,V,Ufluid, etc.) ,
'   FXoverM (= acceleration in x direction)
'   FYoverM (= acceleration in y direction)
'      (These are both defined in separate functions defined below.)
'
'   Reference: Chow, Introduction to Computational Fluid Mechanics, pg. 39
' ****************************************************************************
       
    Dim K As Integer
    Dim Ufluid As Double
    Dim Diameter As Double
    Dim Kinvis As Double
    Dim Amass As Double
    Dim CCoef As Double
    Dim Bgrav As Double, DeltaT As Double
    Dim shMain As Worksheet, shComp As Worksheet
    Dim chMain As ChartObject
    Dim StartTime As Date, EndTime As Date
    Dim Delay As Single

    'These increments are only used internally.
    '-----------------------------------------
    Dim D1X As Double, D1Y As Double, D1U As Double, D1V As Double
    Dim D2X As Double, D2Y As Double, D2U As Double, D2V As Double
    Dim D3X As Double, D3Y As Double, D3U As Double, D3V As Double
    Dim D4X As Double, D4Y As Double, D4U As Double, D4V As Double
    
    Dim X As Double, Y As Double, U As Double, V As Double
    
    'Set Object Variables
    '-----------------------------------------
    Set shComp = Worksheets("Computed Data")
    Set shMain = Worksheets("Main Sheet")
    Set chMain = shMain.ChartObjects("Chart 1")

    
    'Get all the input data from Worksheets.
    '----------------------------------------
    Ufluid = shMain.Range("Ufluid").Value
    Diameter = shMain.Range("Diameter").Value
    Kinvis = shMain.Range("kinvis").Value
    DeltaT = shMain.Range("DeltaT").Value
    Delay = shMain.Range("Delay").Value
        
    X = shComp.Range("F5").Value
    Y = shComp.Range("G5").Value
    U = shComp.Range("H5").Value
    V = shComp.Range("I5").Value
    Amass = shComp.Range("Amass").Value
    Bgrav = shComp.Range("Bgrav").Value
    CCoef = shComp.Range("Ccoef").Value
    
'   Clear all cells from previous run since current run may not use as many.
    '-------------------------------------------
    shComp.Range("E6:I500").ClearContents
    
    'Begin Main Loop.
    'Stop when projectile strikes ground or maximum of 500 timesteps.
    '  (Note: The increments in X and Y in some cases might appear in the
    '   functions on the right, but the FXoverM and FYoverM used here don't
    '   involve position. ????????)
    '-------------------------------------------
    K = 5
    Do While K < 505 And Y >= 0#
    
       StartTime = Timer
       K = K + 1
       
       D1X = DeltaT * U
       D1Y = DeltaT * V
       D1U = DeltaT * FXoverM(U, V, Ufluid, Diameter, Kinvis, Amass, CCoef)
       D1V = DeltaT * FYoverM(U, V, Ufluid, Diameter, Kinvis, Amass, Bgrav, _
                                CCoef)
    
       D2X = DeltaT * (U + 0.5 * D1U)
       D2Y = DeltaT * (V + 0.5 * D1V)
       D2U = DeltaT * FXoverM(U + 0.5 * D1U, V + 0.5 * D1V, Ufluid, _
                                Diameter, Kinvis, Amass, CCoef)
       D2V = DeltaT * FYoverM(U + 0.5 * D1U, V + 0.5 * D1V, Ufluid, _
                                Diameter, Kinvis, Amass, Bgrav, CCoef)
   
       D3X = DeltaT * (U + 0.5 * D2U)
       D3Y = DeltaT * (V + 0.5 * D2V)
       D3U = DeltaT * FXoverM(U + 0.5 * D2U, V + 0.5 * D2V, Ufluid, _
                                Diameter, Kinvis, Amass, CCoef)
       D3V = DeltaT * FYoverM(U + 0.5 * D2U, V + 0.5 * D2V, Ufluid, _
                                Diameter, Kinvis, Amass, Bgrav, CCoef)

       D4X = DeltaT * (U + D3U)
       D4Y = DeltaT * (V + D3V)
       D4U = DeltaT * FXoverM(U + D3U, V + D3V, Ufluid, _
                                Diameter, Kinvis, Amass, CCoef)
       D4V = DeltaT * FYoverM(U + D3U, V + D3V, Ufluid, _
                                Diameter, Kinvis, Amass, Bgrav, CCoef)
           
       'Compute the new values of X, Y, U and V.
       '---------------------------------------------------
       X = X + (D1X + 2# * D2X + 2# * D3X + D4X) / 6#
       Y = Y + (D1Y + 2# * D2Y + 2# * D3Y + D4Y) / 6#
       U = U + (D1U + 2# * D2U + 2# * D3U + D4U) / 6#
       V = V + (D1V + 2# * D2V + 2# * D3V + D4V) / 6#
       
       'Place values in the appropriate cells in the spreadsheet.
       '---------------------------------------------------
       shComp.Range("F" & K).Value = X
       shComp.Range("G" & K).Value = Y
       shComp.Range("H" & K).Value = U
       shComp.Range("I" & K).Value = V
       
       'Update the time value
       '---------------------------------------------------
       shComp.Range("E" & K).Value = DeltaT + shComp.Range("E" & (K - 1)).Value
       
       EndTime = Timer
       While EndTime - StartTime < Delay
          EndTime = Timer
       Wend
       DoEvents
   Loop
   
   'chMain.Visible = True
   
End Sub



Function CDrag(WRelV As Double, Diameter As Double, Kinvis As Double) As Double
' *********************************************************************************
'   Finds the drag coefficient on a SMOOTH sphere as a function of Reynolds number
'   (product of velocity and diameter divided by fluid kinematic viscosity.
'   Based on problem 1.1 in:  An Introduction to Computational Fluid Mechanics
'    by C.Y.Chow, Wiley, 1979.
' *********************************************************************************
    Dim Reynolds As Double
    
    If Kinvis = 0# Then
       Reynolds = 0#
    Else
       Reynolds = Abs(WRelV) * Diameter / Kinvis
    End If
    
    'For Laminar Flow
    '------------------------------------------
    If Reynolds = 0# Then CDrag = 0#
    If Reynolds > 0# And Reynolds <= 1# Then CDrag = 24# / Reynolds
    If Reynolds > 1# And Reynolds <= 400# Then CDrag = 24# / (Reynolds ^ 0.646)
    If Reynolds > 400# And Reynolds <= 300000# Then CDrag = 0.5
    
    'For transition from laminar to turbulent flow:
    '  the Drag Coefficient decreases because turbulent boundary-layer
    '  stays attached longer.  There is less of a wake region behind the sphere.
    '-------------------------------------------
    If (Reynolds > 300000# And Reynolds <= 2000000#) Then
        CDrag = 0.000366 * (Reynolds ^ 0.4275)
    End If
    
    If (Reynolds > 2000000#) Then CDrag = 0.18
    
End Function

 
Function FXoverM(U, V, Ufluid As Double, Diameter As Double, Kinvis As Double, _
    Amass As Double, CCoef As Double) As Double
' ****************************************************************************
'   This function finds the sum of the forces in the X (horizontal) direction
'   divided by mass (= acceleration in the X direction by Newton's 2nd Law).
'
'   U and V are the X and Y components of the projectile velocity.
'   Ufluid and Vfluid are X and Y velocities of the fluid, e.g., the wind.
'   WRelV is the relative velocity between the projectile and the fluid.
'
'   The only force considered here is the fluid drag; the drag coefficient is
'   determined in a separate function (Cdrag).
'   (I had hoped that the constant values of Ufluid, Diameter, Kinvis, Amass and
'    CCoef could be passed in using something other than the function arguments.)
' ****************************************************************************
    
    'Local Variables
    '---------------
    Dim WRelV As Double, VFluid As Double
    
    'Set Vertical fluid (wind) velocity = 0.0 always.
    '------------------------------------------------
    VFluid = 0#
    
    'Compute relative fluid velocity
    '-------------------------------
    WRelV = Sqr((Ufluid - U) ^ 2 + (VFluid - V) ^ 2)
    
    FXoverM = CCoef * CDrag(WRelV, Diameter, Kinvis) * (Ufluid - U) * WRelV / Amass
    
End Function

Function FYoverM(U, V, Ufluid As Double, Diameter As Double, Kinvis As Double, _
    Amass As Double, Bgrav As Double, CCoef As Double) As Double
' ****************************************************************************
'   This function finds the sum of the forces in the Y (vertical) direction
'   divided by mass (= acceleration in the Y direction by Newton's 2nd Law).
'
'   U and V are the X and Y components of the projectile velocity.
'   Ufluid and Vfluid are the x and y velocities of the fluid;
'   WRelV is the relative velocity between the projectile and the fluid.
'
'   The forces include the fluid drag and gravity; the drag coefficient is
'   determined in a separate function (Cdrag).
'
'   This function should return a value of about -9.8 (g) for a typical projectile
'   in air.  When the projectile is going up (+V velocity) the drag will
'   cause this number to go even more negative; when the projectile is
'   coming down, the drag will be in the upward direction, so the
'   number will be larger than -9.8 (less negative).
' ****************************************************************************
    
    'Local Variables
    '------------------------------------
    Dim WRelV As Double, VFluid As Double
    
    'Set Vertical fluid (wind) velocity = 0.0 always.
    '------------------------------------------------
    VFluid = 0#
    
    'Compute relative fluid velocity
    '-------------------------------
    WRelV = Sqr((Ufluid - U) ^ 2 + (VFluid - V) ^ 2)
    
    FYoverM = (-Bgrav + CCoef * CDrag(WRelV, Diameter, Kinvis) * (VFluid - V) _
                * WRelV) / Amass
    
End Function


Sub SetXmax()
' *************************************************
'Set Maximum X-scale
' *************************************************
    Dim shMain As Worksheet, shComp As Worksheet
    Dim chMain As ChartObject
    Dim Xmax As Single
    
    Set shMain = Worksheets("Main Sheet")
    Set chMain = shMain.ChartObjects("Chart 1")

    Xmax = shMain.Range("Xmax").Value
    chMain.Chart.Axes(xlCategory).MaximumScale = Xmax
    
End Sub

Sub SetYmax()
' *************************************************
'Set Maximum Y-scale
' *************************************************
    Dim shMain As Worksheet, shComp As Worksheet
    Dim chMain As ChartObject
    Dim Ymax As Single
    
    Set shMain = Worksheets("Main Sheet")
    Set chMain = shMain.ChartObjects("Chart 1")

    Ymax = shMain.Range("Ymax").Value
    chMain.Chart.Axes(xlValue).MaximumScale = Ymax
    
End Sub

Sub SetX500()
    ' *************************************************
    ' Set maximum scale at 500 for X-axis
    ' *************************************************

    Dim shMain As Worksheet, shComp As Worksheet
    Dim chMain As ChartObject
    'Dim Dummy
    
    Set shMain = Worksheets("Main Sheet")
    Set chMain = shMain.ChartObjects("Chart 1")

    'Testing Stuff
    '-----------------------------------------
    'Dummy = chMain.Chart.SeriesCollection(1).Formula
    'Dummy = chMain.Chart.ChartTitle.Text
    'Dummy = chMain.Chart.Axes(xlCategory).MaximumScale
    'MsgBox Dummy
  
    chMain.Chart.Axes(xlCategory).MaximumScale = 500
    
End Sub
Sub Defaults()

    Dim shMain As Worksheet
    Set shMain = Worksheets("Main Sheet")
    shMain.Range("Angle").Value = 45
    shMain.Range("Velinit").Value = 30
    shMain.Range("Diameter").Value = 0.05
    shMain.Range("Rhoproj").Value = 8000
    shMain.Range("Ufluid").Value = 0
    shMain.Range("rhofluid").Value = 1.19
    shMain.Range("kinvis").Value = 0.0000154
    shMain.Range("ggrav").Value = 9.8
    shMain.Range("DeltaT").Value = 0.1
        
End Sub

