const User = (props) => {
    const user = props.user;
    return (
      <li>{user.firstName} {user.lastName}</li>
    );
  };
  
  export default User;
  