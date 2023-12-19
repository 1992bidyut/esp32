const char html_index[] PROGMEM = R"rawliteral(

<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Button Events</title>
    <style>
      body {
        font-family: Arial, sans-serif;
        background-color: #90e8f2;
        margin: 0;
        display: flex;
        justify-content: center;
        align-items: center;
        height: 100vh;
      }

      .container {
        background-color: #28d9ed; /* Light green */
        border: 1px solid #c3e6cb; /* Darker green */
        color: #155724; /* Dark text color */
        padding: 2%;
        border-radius: 8px;
        box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
        width: auto;
        text-align: center;
      }
      */ .button-container {
        text-align: center;
        display: flex;
      }

      button {
        background-color: #007bff; /* Blue */
        color: #fff;
        padding: 10px 15px;
        border: none;
        border-radius: 4px;
        cursor: pointer;
        margin: 0 10px;
        font-size: large;
      }

      .meter-section {
        text-align: center;
        align-items: center;
      }

      h1 {
        margin: 0%;
      }
      h2 {
        margin-top: 2%;
        color: rgb(221, 247, 243);
      }

      .main-meter-reading {
        padding: 0% !important;
        text-align: center;
        display: flex;
        justify-content: center;
      }
      .main-meter-reading h1 {
        padding: 0% 1% 0% 1%;
        color: #fff;
        font-size: 100px;
      }

      .micro-meter-reading {
        padding: 0% !important;
        text-align: center;
        justify-content: center;
        margin-bottom: 10%;
      }

      .micro-meter-reading h1 {
        padding: 1%;
        color: #f02929;
        font-size: 100px;
      }
      .micro-meter-reading h3 {
        padding: 1%;
        color: #f02929;
      }

      button:hover {
        background-color: #0056b3; /* Darker blue */
      }
    </style>
  </head>
  <body>
    <div class="container">
      <div class="meter-section">
        <h1>WASA Digital Meter</h1>
        <h2>Meter Reading</h2>
        <div class="main-meter-reading">
          <h1 id="index_5">0</h1>
          <h1 id="index_4">0</h1>
          <h1 id="index_3">0</h1>
          <h1 id="index_2">0</h1>
          <h1 id="index_1">0</h1>
        </div>

        <div class="micro-meter-reading">
          <h1 id="index_0">0</h1>
          <h3>Niddle x0.1</h3>
          <h4>Water transfer: <span id="water_amount">0</span> m3</h4>
        </div>
      </div>
      <div class="button-container">
        <button onClick="wifi_config()" id="wifi_config">Connect WiFi</button>
        <button onclick="meter_config()" id="meter_config">Set Reading</button>
      </div>
    </div>
    <script>
      // JavaScript code for button click events
      function wifi_config() {
        window.location.href = "/wifi_config";
      }

      function meter_config() {
        window.location.href = "/meter_config";
      }

      function get_data() {
        console.log("Called!");
        let apiUrl = "/get_meter_reading";
        const outputElement = document.getElementById("output");

        fetch(apiUrl)
          .then((response) => {
            if (!response.ok) {
              throw new Error("Network response was not ok");
            }
            return response.json();
          })
          .then((data) => {
            console.log(data);
            // Display data in an HTML element
            document.getElementById("water_amount").innerHTML = data.water;
            document.getElementById("index_0").innerHTML = data.index_0;
            document.getElementById("index_1").innerHTML = data.index_1;
            document.getElementById("index_2").innerHTML = data.index_2;
            document.getElementById("index_3").innerHTML = data.index_3;
            document.getElementById("index_4").innerHTML = data.index_4;
            document.getElementById("index_5").innerHTML = data.index_5;
          })
          .catch((error) => {
            console.error("Error:", error);
          });
      }
      get_data();

      setTimeout("location.reload(true);", 10000);
      // setTimeout("get_data();", 10000);
    </script>
  </body>
</html>

  
)rawliteral";