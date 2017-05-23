using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PlayerController : MonoBehaviour {

	public float speed;
	public Text countText;
	public Text winText;

	private Rigidbody rb;
	private int counter;

	void Start()
	{
		rb = GetComponent<Rigidbody> ();
		counter = 0;
		SetCountText ();
		winText.text = "";

	}

	//called before any physics calculations
	void FixedUpdate()
	{
		float moveHorizontal = Input.GetAxis ("Horizontal");
		float moveVertical = Input.GetAxis ("Vertical");

		Vector3 movement = new Vector3 (moveHorizontal, 0.0f, moveVertical);

		rb.AddForce (movement * speed);


	}

	void OnTriggerEnter(Collider other) 
	{
		if (other.gameObject.CompareTag ("Pickup")) 
		{
			other.gameObject.SetActive (false);
			counter++;
			SetCountText ();
		}
	}

	void SetCountText()
	{
		countText.text = "Count: " + counter.ToString ();
		if (counter >= 4) {
			winText.text = "You Win!";
		}
	}
}
