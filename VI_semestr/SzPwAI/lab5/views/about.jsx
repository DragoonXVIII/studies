const React = require('react');
const HelloMessage = (props) => {
    return <><div>Nazwisko: {props.nazwisko}</div><div>Email: {props.email}</div><div>Wiek: {props.wiek}</div></>;
}

module.exports = HelloMessage;