import logo from './logo.svg';
import './App.css';
import createModule from './wasm/ceres-core';

function App() {
  const arr_data = new Float64Array([2, 3, 4]);
  // arr_data.push_back(1.0);
  console.log(arr_data);
  createModule().then((Module) => {
    let numericFunction = () => null;

    numericFunction = Module.cwrap('singleVarNumericWASM', 'number');
    numericFunction(3, arr_data, 5);
  });
  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <p>
          Edit <code>src/App.js</code> and save to reload.
        </p>
        <a className="App-link" href="https://reactjs.org" target="_blank" rel="noopener noreferrer">
          Learn React
        </a>
      </header>
    </div>
  );
}

export default App;
