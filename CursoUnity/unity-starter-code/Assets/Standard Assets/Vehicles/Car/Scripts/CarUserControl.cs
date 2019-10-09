using System;
using UnityEngine;
using UnityStandardAssets.CrossPlatformInput;

namespace UnityStandardAssets.Vehicles.Car
{
    [RequireComponent(typeof (CarController))]
    public class CarUserControl : MonoBehaviour
    {
       // add code here
       private CarController m_Car;

        private void Awake()
        {
            // add code here 
            m_Car = GetComponent<CarController>();
            

        }


        private void FixedUpdate()
        {
            // add code here 
            float v = Input.GetAxis("Vertical");
            float h = Input.GetAxis("Horizontal");
            //if !MOBILE_INPUT
            float handbrake = CrossPlatformInputManager.GetAxis("Jump");
            m_Car.Move(h, v, v, handbrake);
            //else
            m_Car.Move(h, v, v, 0f);
            //endif 


        }
    }
}